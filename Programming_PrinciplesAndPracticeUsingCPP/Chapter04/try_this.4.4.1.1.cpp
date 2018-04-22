// Use the example above as a model for a program that converts RUR, UAH, and CNY into dollars. If you like realism,
// you can find conversion rates on the web.
#include "std_lib_facilities.h"

int main()
{
    string currency;
    double amount = 0;

    cout << "Конвертер валют (RUR, UAH, CNY) в доллары США (USD).\n";
    cout << "У вас есть (RUR - российский рубль, UAH - украинская гривна, CNY - китайский юань):\n";
    cin >> currency;
    if (currency == "RUR" || currency == "UAH" || currency == "CNY") {
        cout << "Пожалуйста, введите сумму:\n";
        cin >> amount;
        if (currency == "RUR") {
            cout << "1 RUR = 0.0163 USD, 1 USD = 61.3222 RUR\n";
            cout << "Хотите приобрести: " << amount * 0.0163 << " USD.\n";
        } else if (currency == "UAH") {
            cout << "1 UAH = 0.0382 USD, 1 USD = 26.175 UAH\n";
            cout << "Хотите приобрести: " << amount * 0.0382 << " USD.\n";
        } else if (currency == "CNY") {
            cout << "1 CNY = 0.159 USD, 1 USD = 6.2893 CNY\n";
            cout << "Хотите приобрести: " << amount * 0.159 << " USD.\n";
        }
    }
    else
        cout << "Извините, я не знаю, что такое '"
             << currency << "'\n";
}
