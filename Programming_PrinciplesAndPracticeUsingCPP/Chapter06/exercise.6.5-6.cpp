// 6. Write a program that checks if a sentence is correct according to the “English” grammar in §6.4.1. Assume that
// every sentence is terminated by a full stop (.) surrounded by whitespace. For example, birds fly but the fish swim .
// is a sentence, but birds fly but the fish swim (terminating dot missing) and birds fly but the fish swim. (no space
// before dot) are not. For each sentence entered, the program should simply respond “OK” or “not OK.” Hint: Don’t
// bother with tokens; just read into a string using >>.
#include "std_lib_facilities.h"

/*
 * English grammar
 *
 * Sentence:
 *      Noun Verb                       // e.g., C++ rules
 *      Sentence Conjunction Sentence   // e.g., Birds fly but fish swim
 *
 * Subject:
 *      Noun
 *      "the" Noun
 *
 * Conjunction:
 *      "and"
 *      "or"
 *      "but"
 *
 * Noun:
 *      "birds"
 *      "fish"
 *      "C++"
 *
 * Verb:
 *      "rules"
 *      "fly"
 *      "swim"
 *
*/

class String_stream {
public:
    String_stream();
    string get();
    void putback(string s);
private:
    bool full;
    string buffer;
};

String_stream::String_stream()
        :full(false), buffer("")
{
}

void String_stream::putback(string s)
{
    if (full) error("putback() into a full buffer");
    buffer = s;
    full = true;
}

string String_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    string s = "";
    cin >> s;
    return s;
}

String_stream sstr;

bool Conjunction()
{
    string s = sstr.get();
    if (s == "and" || s == "or" || s == "but")
        return true;
    else
        return false;
}

bool noun()
{
    string s = sstr.get();
    if (s == "birds" || s == "fish" || s == "C++")
        return true;
    else
        return false;
}

bool verb()
{
    string s = sstr.get();
    if (s == "rules" || s == "fly" || s == "swim")
        return true;
    else
        return false;
}

bool subject()
{
    string s = sstr.get();
    if (s == "the")
        return noun();
    else {
        sstr.putback(s);
        return noun();
    }
}

bool sentence()
{
    return (subject() && verb());
}

int main()
try {
    bool is_ok = false;
    while (true) {
        is_ok = sentence();
        if (!is_ok) {
            cout << "Not OK\n";
            return 0;
        }
        string s = sstr.get();
        if (s == ".") {
            cout << "OK\n";
            return 0;
        }
        else {
            sstr.putback(s);
            is_ok = Conjunction();
            if (!is_ok) {
                cout << "Not OK\n";
                return 0;
            }
        }
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
