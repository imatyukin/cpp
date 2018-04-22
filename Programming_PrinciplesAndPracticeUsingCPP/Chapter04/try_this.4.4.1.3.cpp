// Rewrite your currency converter program from the previous Try this to use a switch-statement. Add conversions from
// EUR and GBP. Which version of the program is easier to write, understand, and modify? Why?
#include "std_lib_facilities.h"

int main() {
    char currency = 'R';
    double amount = 0;

    cout << "Конвертер валют (RUR, UAH, CNY, EUR, GBP) в доллары США (USD).\n";
    cout << "У вас есть (R - российский рубль, U - украинская гривна, C - китайский юань, E - ЕВРО, G - фунт стерлингов):\n";
    cin >> currency;
    switch (currency) {
        case 'R':
            cout << "Пожалуйста, введите сумму:\n";
            cin >> amount;
            cout << "1 RUR = 0.0163 USD, 1 USD = 61.3222 RUR\n";
            cout << "Хотите приобрести: " << amount * 0.0163 << " USD.\n";
            break;
        case 'U':
            cout << "Пожалуйста, введите сумму:\n";
            cin >> amount;
            cout << "1 UAH = 0.0382 USD, 1 USD = 26.175 UAH\n";
            cout << "Хотите приобрести: " << amount * 0.0382 << " USD.\n";
            break;
        case 'C':
            cout << "Пожалуйста, введите сумму:\n";
            cin >> amount;
            cout << "1 CNY = 0.159 USD, 1 USD = 6.2893 CNY\n";
            cout << "Хотите приобрести: " << amount * 0.159 << " USD.\n";
            break;
        case 'E':
            cout << "Пожалуйста, введите сумму:\n";
            cin >> amount;
            cout << "1 EUR = 1.2337 USD, 1 USD = 0.8106 EUR\n";
            cout << "Хотите приобрести: " << amount * 1.2337 << " USD.\n";
            break;
        case 'G':
            cout << "Пожалуйста, введите сумму:\n";
            cin >> amount;
            cout << "1 GBP = 1.4056 USD, 1 USD = 0.7114 GBP\n";
            cout << "Хотите приобрести: " << amount * 1.4056 << " USD.\n";
            break;
        default:
            cout << "Извините, я не знаю, что такое '"
                 << currency << "'\n";
            break;
    }
}
