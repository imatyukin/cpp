#include <iostream>

using namespace std;

namespace Chrono941 {
    // Простая структура Date (слишком просто?)
    struct Date {
        int y;                          // Год
        int m;                          // Месяц года
        int d;                          // День месяца
    };

    // Вспомогательные функции:
    void init_day(Date& dd, int y, int m, int d);
    void add_day(Date& dd, int n);

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono941

namespace Chrono942 {
    // Простая структура Date,
    // гарантирующая инициализацию с помощью конструктора
    // и обеспечивающая удобство обозначений
    struct Date {
        int y, m, d;                    // Год, месяц, день
        Date(int yy, int mm, int dd);   // Проверяем корректность даты и выполняем инициализацию
        void add_day(int n);            // Увеличиваем объект на n дней
    };

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono942

namespace Chrono943 {
    // Простой тип Date (управляемый доступ)
    class Date {
        int y, m, d;                    // Год, месяц, день
    public:
        Date(int yy, int mm, int dd);   // Проверка и инициализация даты
        void add_day(int n);            // Увеличение Date на n дней
        int month() const { return m; }
        int day() const { return d; }
        int year() const { return y; }
    };

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono943

namespace Chrono971 {
    enum class Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // Операторы
    Month operator+(const Month& m, int n);
    // Определение других операторов на основе +
    Month operator-(const Month& m, int n);
    Month& operator+=(Month& m, int n);

    bool operator<(const Month& m, int n);
    bool operator>(const Month& m, int n);

    // Простой класс Date (с использованием типа Month)
    class Date {
    public:
        class Invalid { };
        Date(int yy, Month mm, int dd); // Проверка корректности даты и инициализация
        void add_day(int n);            // Увеличение Date на n дней
        Month month() const { return m; }
        int day() const { return d; }
        int year() const { return y; }
    private:
        int y;                          // Год
        Month m;
        int d;                          // День
        bool is_valid();
    };

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono971

namespace Chrono974 {
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // Операторы
    Month operator+(const Month& m, int n);
    // Определение других операторов на основе +
    Month operator-(const Month& m, int n);
    Month& operator+=(Month& m, int n);

    bool operator<(const Month& m, int n);
    bool operator>(const Month& m, int n);

    // Простой класс Date (с использованием типа Month)
    class Date {
    public:
        class Invalid { };
        // Конструктор
        Date(int yy, Month mm, int dd); // Проверка корректности даты и инициализация

        // Константные члены: модифицировать объект не могут
        int year() const { return y; };
        Month month() const { return m; };
        int day() const { return d; };

        // Неконстантные члены: могут модифицировать объект
        void add_year(int n);           // Увеличивает Date на n лет
        void add_month(int n);          // Увеличивает Date на n месяцев
        void add_day(int n);            // Увеличивает Date на n дней
    private:
        int y;                          // Год
        Month m;                        // Месяц
        int d;                          // День месяца
        bool is_valid();
    };

    // Операторы
    ostream& operator<<(ostream& os, const Date& d);
}   // Chrono974