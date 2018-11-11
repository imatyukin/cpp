// 5. This exercise and the next few require you to design and implement a Book class, such as you can imagine as part
// of software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store
// data on whether or not the book is checked out. Create functions for returning those data values. Create functions
// for checking a book in and out. Do simple validation of data entered into a Book; for example, accept ISBNs only of
// the form n-n-n-x where n is an integer and x is a digit or a letter. Store an ISBN as a string.
// 6. Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books.
// Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.
// 7. Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical,
// biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member
// functions.
// 8. Create a Patron class for the library. The class will have a user’s name, library card number, and library fees
// (if owed). Have functions that access this data, as well as a function to set the fee of the user. Have a helper
// function that returns a Boolean (bool) depending on whether or not the user owes a fee.
// 9. Create a Library class. Include vectors of Books and Patrons. Include a struct called Transaction. Have it include
// a Book, a Patron, and a Date from the chapter. Make a vector of Transactions. Create functions to add books to the
// library, add patrons to the library, and check out books. Whenever a user checks out a book, have the library make
// sure that both the user and the book are in the library. If they aren’t, report an error. Then check to make sure
// that the user owes no fees. If the user does, report an error. If not, create a Transaction, and place it in the
// vector of Transactions. Also write a function that will return a vector that contains the names of all Patrons who
// owe fees.

#include "std_lib_facilities.h"
#include "exercise.9.5-9.Library.h"

using namespace MyLibrary;

int main()
try {
    cout << "Exercise 9.5:" << '\n' << endl;

    // Тестирование функции Library::is_isbn()
    string s{};
    string isbn{};

    isbn = "0123-4567-8910-A";
    s = MyLibrary::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "01-2345-678-9";
    s = MyLibrary::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "abcdefghijklmnopqrstuvwxyz";
    s = MyLibrary::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "0123-4567-8910-ABC";
    s = MyLibrary::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "0123-4567--A";
    s = MyLibrary::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "&0123||456-78-91-0";
    s = MyLibrary::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";

    cout << endl;

    // Тестирование класса Book
    Book book{"9780-3219-9278-9", "Programming: Principles and Practice Using C++",
              "Bjarne Stroustrup", 2014, Book::Genre::nonfiction, true};
    MyLibrary::print(cout, book);
    book.check_out();
    MyLibrary::print(cout, book);
    book = Book{"9780-3215-6384-2", "The C++ Programming Language",
              "Bjarne Stroustrup", 2013, Book::Genre::nonfiction, true};
    book.check_in();
    MyLibrary::print(cout, book);
    book.check_out();
    MyLibrary::print(cout, book);
    try {
        book = Book{"???", "A Tour of C++", "Bjarne Stroustrup",
                    2018, Book::Genre::nonfiction, true};
    }
    catch(MyLibrary::Invalid_ISBN& e) {
        cerr << "Invalid ISBN!\n";
    }

    cout << '\n' << "Exercise 9.6:" << '\n' << endl;

    // Тестирование операторов класса Book
    book = Book{"9780-3219-9278-9", "Programming: Principles and Practice Using C++",
              "Bjarne Stroustrup", 2014, Book::Genre::nonfiction, true};
    cout << book;

    Book b1{"9780-3215-6384-2",
            "The C++ Programming Language",
            "Bjarne Stroustrup", 2013, Book::Genre::nonfiction, true};
    Book b2{"9780-3215-6384-2",
            "The C++ Programming Language",
            "Bjarne Stroustrup", 2013, Book::Genre::nonfiction, true};

    if (b1 == b2) cout << '\n' << b1
                       << "\n-- is the same book as --\n\n"
                       << b2 << '\n';
    cout << "----------------------\n";
    if (book != b2) cout << '\n' << book
                         << "\n-- is not the same book as --\n\n"
                         << b2 << '\n';

    cout << "Exercise 9.7:" << '\n' << endl;

    // Тестирование перечисления Genre для класса Book и его типов
    book = Book{"9780-3219-9278-9", "Programming: Principles and Practice Using C++",
              "Bjarne Stroustrup", 2014,
              Book::Genre::nonfiction, true};
    cout << book;

    book = Book{"9780-1560-2760-1", "Solaris", "Stanislaw Lem",
                2002, Book::Genre::fiction, true};
    cout << book;

    book = Book{"9781-5932-7407-8", "Python for Kids: A Playful Introduction To Programming",
                "Jason R. Briggs", 2012,
                Book::Genre::children, true};
    cout << book;

    book = Book{"9781-2500-7483-6", "Limonov", "Emmanuel Carrère",
                2015, Book::Genre::biography, true};
    cout << book;

    cout << '\n' << "Exercise 9.8:" << '\n' << endl;

    // Тестирование типа Patron
    Patron patron{"Igor Matyukin", 1, 0};
    cout << patron;

    // Тестирование вспомогательного метода owes_fees()
    if (owes_fees(patron)) cout << "Пользователь заплатил членский взнос.\n";
    else cout << "Членский взнос не оплачен.\n";

    // Тестирование функции Patron::set_fees(), устанавливающей размер членского взноса
    patron.set_fees(39.5);
    cout << endl;
    cout << "Оплата членского взноса ...\n" << patron;
    if (owes_fees(patron)) cout << "Пользователь заплатил членский взнос.\n";
    else cout << "Членский взнос не оплачен.\n";

    // Тестирование ошибки для Patron::set_fees()
    try {
        patron.set_fees(-39.5);
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
    }

    cout << '\n' << "Exercise 9.9:" << '\n' << endl;

    Book mybook{"9780-3219-9278-9",
              "Programming: Principles and Practice Using C++",
              "Bjarne Stroustrup",
              2014,
              Book::nonfiction,
              false};

    cout << mybook;

    return 0;
}
catch (runtime_error e) {	// этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {	// этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}