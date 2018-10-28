#include "std_lib_facilities.h"
#include "exercise.9.5-7.Library.h"

namespace Library {

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
            char c{isbn[i]};    // рассматривается текущий символ

            // если меньше трёх дефисов, то ищется цифра или дефис
            if (hyphen < 3) {
                if (!isdigit(c)) {
                    if (c == '-' && n) {    // дефис отмечает конец числа
                        ++hyphen;
                        n = false;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    // является цифрой, поэтому находимся на числе
                    n = true;
                }
            }
            else {  // После третьего дефиса должен быть только символ
                if (i != (isbn.size()-1)) return false;
                // символ должен быть цифра или буква
                return (isdigit(c) || isalpha(c));
            }
        }
        // если цикл заканчивается без возврата, код ISBN недопустимой формы
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

}   // namespace Library