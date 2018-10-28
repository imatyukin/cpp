// 5. This exercise and the next few require you to design and implement a Book class, such as you can imagine as part
// of software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store
// data on whether or not the book is checked out. Create functions for returning those data values. Create functions
// for checking a book in and out. Do simple validation of data entered into a Book; for example, accept ISBNs only of
// the form n-n-n-x where n is an integer and x is a digit or a letter. Store an ISBN as a string.
//
// 6. Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books.
// Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.

#include "std_lib_facilities.h"
#include "exercise.9.5-6.Library.h"

using namespace Library;

int main()
try {
    cout << "Exercise 9.5:" << '\n' << endl;

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

    cout << endl;

    // Тестирование класса Book
    Book book{"9780-3219-9278-9", "Programming: Principles and Practice Using C++",
              "Bjarne Stroustrup", 2014, true};
    Library::print(cout, book);
    book.check_out();
    Library::print(cout, book);
    book = Book{"9780-3215-6384-2", "The C++ Programming Language",
              "Bjarne Stroustrup", 2013, true};
    book.check_in();
    Library::print(cout, book);
    book.check_out();
    Library::print(cout, book);
    try {
        book = Book{"???", "A Tour of C++", "Bjarne Stroustrup",
                    2018, true};
    }
    catch(Library::Invalid_ISBN& e) {
        cerr << "Invalid ISBN!\n";
    }

    cout << '\n' << "Exercise 9.6:" << '\n' << endl;

    // Тестирование операторов класса Book
    Book book1{"9780-3219-9278-9", "Programming: Principles and Practice Using C++",
              "Bjarne Stroustrup", 2014, true};
    cout << book1;

    Book b1{"9780-3215-6384-2",
            "The C++ Programming Language",
            "Bjarne Stroustrup", 2013, true};
    Book b2{"9780-3215-6384-2",
            "The C++ Programming Language",
            "Bjarne Stroustrup", 2013, true};

    if (b1 == b2) cout << '\n' << b1
                       << "\n-- is the same book as --\n\n"
                       << b2 << '\n';
    cout << "----------------------\n";
    if (book1 != b2) cout << '\n' << book1
                         << "\n-- is not the same book as --\n\n"
                         << b2 << '\n';

    return 0;
}
catch (runtime_error e) {	// этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {	// этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}