// 4. Look at the headache-inducing last example of §8.4. Indent it properly and explain the meaning of each construct.
// Note that the example doesn’t do anything meaningful; it is pure obfuscation.

struct X {                          // struct X с функциями-членами f(), g(), X(), m3() и main(), переменная-член m
    void f(int x)                   // функция f() в X
    {
        struct Y {                  // struct Y внутри f()
            int f() { return 1; }   // функция-член Y
            int m;                  // элемент данных Y
        };

        int m;                      // переменная внутри f()
        m = x;                      // устанавливает m в аргумент f()
        Y m2;                       // объявляет переменную типа Y
        return f(m2.f());           // f возвращает результат f, вызванный с m2.f(), который равен 1.
                                    // Бесконечная рекурсия?
    }
    int m;                          // элемент данных X

    void g(int m)                   // функция g() в X
    {
        if (m)                      // если аргумент g() не равен нулю
            f(m+2);                 // вызывает X.f() с аргументом m+2
        else {                      // если аргумент g() равен нулю
            g(m+2);                 // вызывает g() с аргументом m+2, который равен 2
        }
    }

    X() { }                         // конструктор по умолчанию для структуры X
    void m3() { }                   // функция-член m3() структуры X, ничего не делает, ничего не возвращает

    void main()                     // функция-член main() структуры X
    {
        X a;                        // объявляет переменную типа X, использует конструктор по умолчанию,
                                    // int m не инициализирован
        a.f(2);                     // вызывает X.f() с аргументом 2
    }
};