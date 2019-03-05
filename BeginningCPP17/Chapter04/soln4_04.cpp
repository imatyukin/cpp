// Exercise 4-4.
// It’s time to make good on a promise. Somewhere in this chapter we said we’d look for someone “who is older than 21,
// younger than 35, is female, has a bachelor’s or master’s degree, is unmarried, and speaks Hindi or Urdu.” Write a
// program that prompts the user for these qualifications and then outputs whether they qualify for these very specific
// requirements. To this end, you should define an integer variable age, a character variable gender (to hold 'm' for
// male and 'f' for female), a variable degree of an enumeration type AcademicDegree (possible values: none, associate,
// bachelor, professional, master, doctor), and three Boolean variables: married, speaksHindi, and speaksUrdu. Emulate a
// trivial online job interview, and query your applicant for input on all these variables. People who enter invalid
// values do not qualify, of course, and should be ruled out as early as possible (that is, immediately after entering
// any invalid value; ruling them out precognitively prior to entering invalid values, sadly, is not possible yet in
// Standard C++).
#include <iostream>

int main() {
    int age {};
    char gender {};
    enum AcademicDegree {
        none = 'n',
        associate = 'a',
        bachelor = 'b',
        professional = 'p',
        master = 'm',
        doctor = 'd'
    };
    AcademicDegree academicDegree {};
    char degree {};
    char yesno {};
    bool married {true};
    bool speaksHindi {};
    bool speaksUrdu {};

    std::cout << "Emulation of a trivial online job interview." << std::endl;
    std::cout << std::endl;

    std::cout << "Your age: ";
    std::cin >> age;
    if (age > 21 && age < 35) {
        std::cout << "Your gender ('m' for male or 'f' for female): ";
        std::cin >> gender;
        if (std::tolower(gender) == 'f') {
            std::cout << "Your highest academic degree\n"
                      << "(possible values: none, associate, bachelor, professional, master, doctor): ";
            std::cin >> degree;
            switch (std::tolower(degree)) {
                case none:
                case associate:
                case professional:
                case doctor:
                    break;
                case bachelor:
                    academicDegree = AcademicDegree::bachelor;
                    break;
                case master:
                    academicDegree = AcademicDegree::master;
                    break;
                default:
                    break;
            }
        }

        if (academicDegree == AcademicDegree::bachelor || academicDegree == AcademicDegree::master) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Are you married (Y/N)? ";
            std::cin >> yesno;
            if (std::toupper(yesno) == 'N') {
                married = false;
            }
            if (!married) {
                std::cout << "Do you speak Hindi (Y/N)? ";
                std::cin >> yesno;
                if (std::toupper(yesno) == 'Y') {
                    speaksHindi = true;
                }
                std::cout << "Do you speak Urdu (Y/N)? ";
                std::cin >> yesno;
                if (std::toupper(yesno) == 'Y') {
                    speaksUrdu = true;
                }
                std::cout << (speaksHindi || speaksUrdu ? "You are qualified." : "You are not qualified.");
            }
            else { std::cout << "You are not qualified." << std::endl; return 1; }
        }
        else { std::cout << "You are not qualified." << std::endl; return 1; }
    }
    else { std::cout << "You are not qualified." << std::endl; return 1; }
}