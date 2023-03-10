

#include <iostream>
#include <cmath>



double fun(double x, double a, double b) {
    
    return ((a * (sin(x)*sin(x))) + (b * log10(x)));
}

bool up(double x, double a, double b, double e) {
    if (fun(x, a, b) < fun(x + e, a, b)) {
        return 1;
    }
    else {
        return 0;
    }
}

using namespace std;

int main()
{
    //продолжение
    setlocale(LC_ALL, "Russian");
    double e = 0.0003;
    double x0, x1, x2, a, b;
    double f2;
  
    int n=0;
    while (1)
    {
        cout << "Введите A: ";
        cin >> a;
        cout << "Ввелите B: ";
        cin >> b;
        cout << "Введите Епсилон: ";
        cin >> e;
        cout << "Введите интервал, на котором будет производиться поиск корней:\n";
        cout << "левая граница x0: ";
        cin >> x0;
        cout << "правая граница x1: ";
        cin >> x1;

        cout << "Ваш интервал [" << x0 << ", " << x1 << "]\n";
        cout << "f(x) = (a * pow(sin(x), 2) + b * log(x))\n";

        while (abs(x1 - x0) > e) {

            double f0 = fun(x0, a, b); //левая часть
            double f1 = fun(x1, a, b); //правая часть

         /*   if (f0 * f1 > 0) {
                cout << "Ошибка, функция не меняет знак. Метод биссекции может быть некорретным\n";
                break;
            }*/

            x2 = (x1 + x0) / 2;
            f2 = fun(x2, a, b); //середина

            if (!up(x2, a, b, e))
            {
                if (f2 >= 0) {

                    x0 = x2;
                }
                else
                {
                    x1 = x2;
                }
                n += 1;
            }
            else
            {
                if (f2 >= 0) {

                    x1 = x2;
                }
                else
                {
                    x0 = x2;

                }
                n += 1;
            }

        }

        cout << "Корень: " << x2 << " F(x)= " << f2 << "\nКоличество итераций n: " << n << "\n\n";


    }
    cout << "\nДля продолжения нажмите Enter\n";
    getchar();
}
