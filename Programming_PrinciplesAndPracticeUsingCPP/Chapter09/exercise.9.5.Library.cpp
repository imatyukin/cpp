#include "std_lib_facilities.h"
#include "exercise.9.5.Library.h"

namespace Library {

    Book::Book(string isbn, string title, string author, int copyright_date, bool checked_out)
        :id{isbn}, t{title}, a{author}, cd{copyright_date}, co{false}
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
        // если цикл заканчивается без возврата, формат недействителен
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

}   // namespace Library