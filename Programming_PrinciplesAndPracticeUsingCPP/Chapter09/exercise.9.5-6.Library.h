#include "std_lib_facilities.h"

namespace Library {

    // в случае, если код ISBN недопустимой формы
    class Invalid_ISBN { }; // код ISBN допускается только в форме n-n-n-x, где n - целое число; x - цифра или буква

    // класс Book
    class Book {
    public:
        // конструкторы
        Book(string isbn, string title, string author, int copyright_date, bool checked_out);
        Book(); // конструктор по умолчанию

        // Константные члены: модифицировать объект не могут
        string isbn() const { return id; }
        string title() const { return t; }
        string author() const { return a; }
        int copyright_date() const { return cd; }
        bool checked_out() const { return co; }

        // Неконстантные члены: могут модифицировать объект
        void check_out() { co = true; }
        void check_in() { co = false; }

    private:
        string id;  // код ISBN
        string t;   // название книги
        string a;   // фамилия автора
        int cd;     // дата регистрации авторских прав
        bool co;    // данные о том, выдана книга на руки или нет
    };

    // вспомогательные функции

    bool is_isbn(const string& isbn);   // true, если код ISBN допустимой формы
    void print(ostream& os, const Book& book);

    // Операторы класса Book

    // == проверяет, совпадают ли коды ISBN у двух книг
    bool operator==(const Book& b1, const Book& b2);
    // != сравнивает коды ISBN
    bool operator!=(const Book& b1, const Book& b2);
    // << выводит в поток название, фамилию автора и код ISBN в отдельных строках
    ostream& operator<<(ostream& os, const Book& book);

}   // namespace Library
