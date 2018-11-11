#include "std_lib_facilities.h"
#include "exercise.9.5-9.Library.h"

namespace MyLibrary {

    // Функции, имеющие доступ к членам класса Book
    Book::Book(string isbn, string title, string author, int copyright_date, Genre genre, bool checked_out)
        :id{isbn}, t{title}, a{author}, cd{copyright_date}, g{genre}, co{false}
    {
        if (!is_isbn(isbn)) throw Invalid_ISBN{};
    }

    bool is_isbn(const string& isbn)
    // Проверка данных: код ISBN допускается только в форме n-n-n-x, где n - целое число, x - цифра или буква
    {
        int hyphen{0};  // Количество найденных дефисов
        bool n{false};  // Проходится число

        for (size_t i = 0; i < isbn.size(); ++i) {
            char c{isbn[i]};    // Рассматривается текущий символ

            // Если меньше трёх дефисов, то ищется цифра или дефис
            if (hyphen < 3) {
                if (!isdigit(c)) {
                    if (c == '-' && n) {    // Дефис отмечает конец числа
                        ++hyphen;
                        n = false;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    // Является цифрой, поэтому находимся на числе
                    n = true;
                }
            }
            else {  // После третьего дефиса должен быть только символ
                if (i != (isbn.size()-1)) return false;
                // Символ должен быть цифра или буква
                return (isdigit(c) || isalpha(c));
            }
        }
        // Если цикл заканчивается без возврата, код ISBN недопустимой формы
        return false;
    }

    void print(ostream& os, const Book& book)
    {
        os << book.title() << '\n'
           << "  Автор: " << book.author() << '\n'
           << "  ISBN: " << book.isbn() << '\n'
           << "  Дата регистрации авторских прав: " << book.copyright_date() << '\n'
           << "  Выдана книга на руки или нет: ";
        if (book.checked_out()) os << "ДА\n";
        else os << "НЕТ\n";
    }

    string parse_genre(const Book::Genre& genre) {

        switch (genre) {
            case Book::Genre::fiction:
                return "Fiction";
            case Book::Genre::nonfiction:
                return "Non fiction";
            case Book::Genre::periodical:
                return "Periodical";
            case Book::Genre::biography:
                return "Biography";
            case Book::Genre::children:
                return "Children";
            default:
                return "Unknown genre";
        }
    }

    // Операторы класса Book
    bool operator==(const Book& b1, const Book& b2)
    {
        return (b1.isbn() == b2.isbn());
    }

    bool operator!=(const Book& b1, const Book& b2)
    {
        return !(b1 == b2);
    }

    ostream& operator<<(ostream& os, const Book& book)
    {
        os << book.title() << '\n'
           << "  Author: " << book.author() << endl
           << "  ISBN: " << book.isbn() << endl
           << "  Genre: " << parse_genre(book.genre()) << endl;

        return os;
    }

    // Функции, имеющие доступ к членам класса Patron
    Patron::Patron(string name, int card_number, double fees)
          :n{name}, cn{card_number}, f{fees}
    {
    }

    const Patron& default_patron()
    {
        static const Patron p("",0,0);
        return p;
    }

    Patron::Patron()
          :n(default_patron().name()),
          cn(default_patron().card_number()),
          f(default_patron().fees())
    {
    }

    void Patron::set_fees(double fee)
    {
        if (fee < 0) error("Patron::set_fees(): размер членского взноса не может быть меньше нуля");
        f = fee;
    }

    // Вспомогательный метод
    bool owes_fees(const Patron& p)
    {
        return p.fees() > 0;
    }

    // Оператор класса Patron
    ostream& operator<<(ostream& os, const Patron& p)
    {
        os << "Имя пользователя: " << p.name() << endl
           << "Номер библиотечной карточки: " << p.card_number() << endl
           << "Размер членского взноса: " << p.fees() << endl;

        return os;
    }

    bool operator==(const Patron& p1, const Patron& p2)
    {
        return (p1.card_number() == p2.card_number());
    }

    bool operator!=(const Patron& p1, const Patron& p2)
    {
        return !(p1 == p2);
    }

    // Структура Transaction класса Library, с включенными в ней членами классов Book, Patron и Date
    Library::Transaction::Transaction(Book bb, Patron pp, Chrono::Date dd)
            :b(bb), p(pp), d(dd)
    {
    }

    // Класс Library
    Library::Library(vector<Book> b, vector<Patron> p, vector<Transaction> t)
            :books(b), patrons(p), transactions(t)
    {
    }

    // Функция добавляющая записи о книгах
    void Library::add_book(const Book& b)
    {
        // Проверка, находится ли книга в библиотеке
        for (int i = 0; i<books.size(); ++i) {
            if (books[i] == b) error("add_book(): книга уже в библиотеке");
        }
        books.push_back(b);
    }

    // Функция добавляющая записи о клиентах библиотеки
    void Library::add_patron(const Patron& p)
    {
        // Проверка, зарегистрирован ли пользователь
        /*
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i] == p) error("add_patron(): пользователь уже зарегистрирован");
        }
        */
        patrons.push_back(p);
    }

    void Library::check_out(Book& b, const Patron& p, const Chrono::Date& d)
    {
        // Проверка нахождения книги в библиотеке
        bool b_exists = false;
        int b_idx = 0;
        for (int i = 0; i<books.size(); ++i) {
            if (books[i] == b) {
                b_exists = true;
                b_idx = i;
                break;  // нет необходимости смотреть дальше
            }
        }
        if (!b_exists) error("check_out(): книги в библиотеке нет");

        // Проверка выдачи книги
        if (books[b_idx].checked_out()) error("check_out(): книга уже выдана читателю");

        // Проверка регистрирации пользователя
        bool p_exists = false;
        int p_idx = 0;
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i] == p) {
                p_exists = true;
                p_idx = i;
                break;  // нет необходимости смотреть дальше
            }
        }
        if (!p_exists) error("check_out(): пользователь не зарегистрирован");

        // Проверка, есть ли задолженность по уплате членских взносов у пользователя
        if (patrons[p_idx].fees() > 0) error("check_out(): у пользователя есть задолженность по уплате членских взносов");

        // создание Transaction
        transactions.push_back(Transaction(books[b_idx],patrons[p_idx],d));
        books[b_idx].check_out();
    }

    void Library::set_fee(const Patron& p, double f)
    {
        // Нахождение пользователя
        int idx = 0;
        bool exists = false;
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i] == p) {
                exists = true;
                idx = i;
                break;
            }
        }
        if (!exists) error("Library::set_fee(): пользователь не существует");
        patrons[idx].set_fees(f);
    }

    vector<Patron> Library::get_debtors() const
    {
        vector<Patron> debtors;
        for (int i = 0; i<patrons.size(); ++i) {
            if (patrons[i].fees() > 0)
                debtors.push_back(patrons[i]);
        }
        return debtors;
    }

}   // namespace MyLibrary