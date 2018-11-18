#include "std_lib_facilities.h"
#include "exercise.9.5-9.Chrono.h"

namespace MyLibrary {

    // В случае, если код ISBN недопустимой формы
    class Invalid_ISBN { }; // Код ISBN допускается только в форме n-n-n-x, где n - целое число; x - цифра или буква

    // Класс Book
    class Book {
    public:
        // Перечисление типов для класса Book: фантастика, проза, периодические издания, биографии и детская литература
        enum Genre {
            fiction, nonfiction, periodical, biography, children
        };

        // Конструкторы
        Book(string isbn, string title, string author, int copyright_date, Genre genre, bool checked_out);
        Book(); // Конструктор по умолчанию

        // Константные члены: модифицировать объект не могут
        string isbn() const { return id; }
        string title() const { return t; }
        string author() const { return a; }
        int copyright_date() const { return cd; }
        Genre genre() const { return g; }
        bool checked_out() const { return co; }

        // Неконстантные члены: могут модифицировать объект
        void check_out() { co = true; }
        void check_in() { co = false; }

    private:
        string id;  // Код ISBN
        string t;   // Название книги
        string a;   // Фамилия автора
        int cd;     // Дата регистрации авторских прав
        Genre g;    // Жанр книги
        bool co;    // Данные о том, выдана книга на руки или нет
    };

    // Вспомогательные методы

    bool is_isbn(const string& isbn);   // True, если код ISBN допустимой формы
    void print(ostream& os, const Book& book);
    string parse_genre(const Book::Genre& genre);

    // Операторы класса Book

    // == проверяет, совпадают ли коды ISBN у двух книг
    bool operator==(const Book& b1, const Book& b2);
    // != сравнивает коды ISBN
    bool operator!=(const Book& b1, const Book& b2);
    // << выводит в поток название, фамилию автора и код ISBN в отдельных строках
    ostream& operator<<(ostream& os, const Book& book);

    // Класс Patron
    class Patron {
    public:
        // Конструкторы
        Patron(string name, int card_number, double fees);
        Patron();

        // Константные члены: модифицировать объект не могут
        string name() const { return n; }
        int card_number() const { return cn; }
        double fees() const { return f; }

        // Неконстантные члены: могут модифицировать объект
        void set_fees(double fee); // Функция, устанавливающая размер членского взноса
    private:
        string n;   // Имя пользователя
        int cn;     // Номер библиотечной карточки
        double f;   // Размер членского взноса
    };

    // Вспомогательный метод

    bool owes_fees(const Patron& p); // Заплатил ли пользователь членские взносы

    // Оператор класса Patron

    ostream& operator<<(ostream& os, const Patron& p);
    bool operator==(const Patron& p1, const Patron& p2);
    bool operator!=(const Patron& p1, const Patron& p2);

    // Класс Library
    class Library {
    public:
        // Структура Transaction для членов классов Book, Patron и Date
        struct Transaction {
            Book book;
            Patron patron;
            Chrono::Date date;

            Transaction(Book bb,Patron pp,Chrono::Date dd);
        };

        // Функция добавляющая записи о книгах
        void add_book(Book b);
        // Функция добавляющая записи о клиентах библиотеки
        void add_patron(Patron p);
        // Функция о состоянии книг (выдана ли книга читателю)
        void check_out(Book b, Patron p, Chrono::Date d);
        // Функция добавления членских взносов
        void set_fee(Patron p, double f);

        // Отчёты
        // Возвращает имена пользователей имеющих задолженности по уплате членских взносов
        vector<string> with_fees() const;
        void print_books(ostream& os) const;
        void print_patrons(ostream& os) const;
        void print_transactions(ostream& os) const;
    private:
        // Векторы объектов классов Book, Patron и Transaction
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;
    };

    // Оператор транзакций
    ostream& operator<<(ostream& os, const Library::Transaction& t);

}   // namespace MyLibrary