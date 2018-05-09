// 10. Write a program that plays the game “Rock, Paper, Scissors.” If you are not familiar with the game do some
// research (e.g., on the web using Google). Research is a common task for programmers. Use a switch-statement to solve
// this exercise. Also, the machine should give random answers (i.e., select the next rock, paper, or scissors
// randomly). Real randomness is too hard to provide just now, so just build a vector with a sequence of values to be
// used as “the next value.” If you build the vector into the program, it will always play the same game, so maybe you
// should let the user enter some values. Try variations to make it less easy for the user to guess which move the
// machine will make next.
#include "std_lib_facilities.h"
#include <random>
std::random_device rd;
std::mt19937 gen{rd()};
std::uniform_int_distribution<> dis{0, 2};

int main() {
    vector<string> rock_paper_scissors(2);
    rock_paper_scissors[0] = "Камень";
    rock_paper_scissors[1] = "Ножницы";
    rock_paper_scissors[2] = "Бумага";
    int comp_generator;
    char your_choice;
    string comp_choice;

    cout << "Введите один из трёх знаков: камень 'R', ножницы 'S' или бумагу 'P'" << endl;
    cout << "Камень… Ножницы… Бумага… Раз… Два… Три" << endl;

    while (cin>>your_choice) {

        comp_generator = dis(gen);
        if (comp_generator == 0)
            comp_choice = rock_paper_scissors[0];
        else if (comp_generator == 1)
            comp_choice = rock_paper_scissors[1];
        else
            comp_choice = rock_paper_scissors[2];

        switch (your_choice) {
            case 'r':
            case 'R':
                cout << "Вы Камень vs компьютер " << comp_choice << endl;
                switch (comp_generator) {
                    case 0:
                        cout << "Ничья. Вы и компьютер показали одинаковый знак" << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                    case 1:
                        cout << "Вы победили. Камень побеждает ножницы («камень затупляет или ломает ножницы»)"
                             << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                    case 2:
                        cout << "Вы проиграли. Бумага побеждает камень («бумага накрывает камень»)" << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                }
                break;
            case 's':
            case 'S':
                cout << "Вы Ножницы vs компьютер " << comp_choice << endl;
                switch (comp_generator) {
                    case 0:
                        cout << "Вы проиграли. Камень побеждает ножницы («камень затупляет или ломает ножницы»)"
                             << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                    case 1:
                        cout << "Ничья. Вы и компьютер показали одинаковый знак" << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                    case 2:
                        cout << "Вы победили. Ножницы побеждают бумагу («ножницы разрезают бумагу»)" << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                }
                break;
            case 'p':
            case 'P':
                cout << "Вы Бумага vs компьютер " << comp_choice << endl;
                switch (comp_generator) {
                    case 0:
                        cout << "Вы победили. Бумага побеждает камень («бумага накрывает камень»)" << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                    case 1:
                        cout << "Вы проиграли. Ножницы побеждают бумагу («ножницы разрезают бумагу»)" << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                    case 2:
                        cout << "Ничья. Вы и компьютер показали одинаковый знак" << endl;
                        cout << "\n" << endl;
                        cout << "Камень 'R'… Ножницы 'S'… Бумага 'P'… Раз… Два… Три" << endl;
                        break;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
