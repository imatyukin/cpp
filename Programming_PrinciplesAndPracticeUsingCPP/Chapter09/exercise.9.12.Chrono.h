// Файл exercise.9.12.Chrono.h

#include <iostream>

using namespace std;

namespace Chrono {

    enum class Day {	// sunday==0
        sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };

    // Перегрузка операторов класса Day
    Day operator+(const Day& d, int n);
    Day& operator+=(Day& d, int n);

    ostream& operator<<(ostream& os, const Day& d);

    enum class Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    // Вспомогательные функции класса Month
    int month_days(Month m, int y);             // Возвращает дней в месяце (обычный или високосный год)

    // Перегрузка операторов класса Month
    Month operator+(const Month& m, int n);
    Month& operator++(Month& m);

    // Константы эпохи
    constexpr int epoch_year{1970};             // Минимальное представление даты
    constexpr Day epoch_dow{Day::thursday};     // День недели 1970/1/1

    class Date {
    public:
        class Invalid { };                      // Для генерации исключений

        Date(int yy, Month mm, int dd);         // Проверка корректности и инициализация
        Date(long int days);                    // Инициализация по дням с эпохи
        Date();                                 // Конструктор по умолчанию
        // Копирование по умолчанию нас устраивает

        // Немодифицирующие операции:
        int   day()   const;
        Month month() const;
        int   year()  const;
        long int days_since_epoch() const;

        // Модифицирующие операции:
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        long int dse;       // Дней, прошедших с 1 января 1970 года (так называемого нулевого дня)
    };

    // Вспомогательные функции Date
    bool leapyear(int y);                                   // True для високосного года
    long int days_since_epoch(int y, Month m, int d);       // Преобразование из y/m/d
    int n_leaps(int y);                                     // Все годы от эпохи до у (исключая)
    bool is_date(int y, Month m, int d);                    // True для корректной даты
    Day day_of_week(const Date& d);                         // День недели d
    Date next_Sunday(const Date& d);                        // Следующее воскресенье после d
    Date next_workday(const Date& d);                       // Следующий рабочий день после d
    int week_of_year(const Date& d);                        // Порядковая неделя года d

    // Перегрузка операторов класса Date
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);
    bool operator<=(const Date&a, const Date& b);

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, Date& dd);


} // namespace Chrono