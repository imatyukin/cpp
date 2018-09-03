// 2. Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for “labeling” the
// output and a vector.
// 3. Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector,
// write a function, fibonacci(x,y,v,n), where integers x and y are ints, v is an empty vector<int>, and n is the number
// of elements to put into v; v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence
// where each element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13,
// 21, . . . . Your fibonacci() function should make such a sequence starting with its x and y arguments.

#include "std_lib_facilities.h"

void print(vector<int>& v, const string& name)
// Выводит в поток cout вектор целых чисел
// "Метка" результатов - имя
{
    cout << name << ": (" << v.size() << ") {";
    for (int i = 0; i<v.size(); ++i) {
        if (i%8==0) cout << "\n   ";    // избежать длинных линий
        cout << v[i];
        if (i<v.size()-1) cout << ", "; // беспорядочный; чтобы избежать запятой
    }
    cout << "\n}\n";
}

void fibonacci(int x, int y, vector<int>& v, int n)
// Заполняет v с n элементами ряда Фибоначчи, начиная с x y
{
    // В начале низкие значения n
    if (n<1) return;
    if (1<=n) v.push_back(x);
    if (1<=2) v.push_back(y);

    // Здесь идёт реальная генерация последовательности:
    for (int i=2; i<n; ++i) {           // Первоначально v[0]==x и v[1]==y
        int z = x+y;                    // Следующий элемент
        v.push_back(z);
        x = y;                          // переместить последовательность на
        y = z;
    }
}

int main()
try
{
    vector<int> vtest;
    vtest.push_back(2);
    vtest.push_back(4);
    vtest.push_back(2);
    vtest.push_back(-1);
    print(vtest,"vtest");

    cout<< "Введите два целочисленных значения (будут использоваться для запуска последовательности Фибиначчи) и "
           "количество элементов последовательности: ";
    int val1 = 0;
    int val2 = 0;
    int n;
    while (cin>>val1>>val2>>n) {        // Читает два целочисленных значения
        vector<int> vf;
        fibonacci(val1,val2,vf,n);
        cout << "Фибоначчи(" << val1 << "," << val2 << ") ";
        print(vf,"");
        cout << "Попробуйте снова: ";
    }
}
catch (runtime_error e) {               // этот код предназначен для создания сообщений об ошибках
    cout << e.what() << '\n';
}
catch (...) {                           // этот код предназначен для создания сообщений об ошибках
    cout << "exiting\n";
}