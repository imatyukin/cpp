// 5. This exercise and the next few require you to design and implement a Book class, such as you can imagine as part
// of software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store
// data on whether or not the book is checked out. Create functions for returning those data values. Create functions
// for checking a book in and out. Do simple validation of data entered into a Book; for example, accept ISBNs only of
// the form n-n-n-x where n is an integer and x is a digit or a letter. Store an ISBN as a string.

#include "std_lib_facilities.h"
#include "exercise.9.5.Library.h"

using namespace Library;

int main()
try {
    // Тестирование функции Library::is_isbn()
    string s{};
    string isbn{};

    isbn = "0123-4567-8910-A";
    s = Library::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "01-2345-678-9";
    s = Library::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "abcdefghijklmnopqrstuvwxyz";
    s = Library::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "0123-4567-8910-ABC";
    s = Library::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "0123-4567--A";
    s = Library::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "&0123||456-78-91-0";
    s = Library::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";

    return 0;
}
catch (runtime_error e) {	// этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {	// этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}