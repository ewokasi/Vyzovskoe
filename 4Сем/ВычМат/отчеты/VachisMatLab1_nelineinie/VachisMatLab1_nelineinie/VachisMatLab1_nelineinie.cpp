#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double a, double b) {
    return a * sin(x) * sin(x) + b * log10(x);
}

double df(double x, double a, double b) {
    return 2 * a * sin(x) * cos(x) / x + b / x;
}

double ddf(double x, double a, double b) {
    return -2 * a * sin(x) * sin(x) / (x * x) + 2 * a * cos(x) * cos(x) / x / x - b / x / x;
}

double combinedMethod(double a, double b, double x0, double x1, double eps) {
    double x = x1;
    double x_prev = x0;
    double fx = f(x, a, b);
    double fx_prev = f(x_prev, a, b);
    double dfx = df(x, a, b);
    double ddfx = ddf(x, a, b);

    int iterations = 0;

    while (abs(fx) > eps) {
        double x_next;
        double dfx_prev = df(x_prev, a, b);
        double ddfx_prev = ddf(x_prev, a, b);
        if (dfx * dfx_prev > 0) {
            // use secant method
            x_next = x - fx * (x - x_prev) / (fx - fx_prev);
        }
        else {
            // use Newton's method
            x_next = x - fx / dfx;
        }
        if (abs(x_next - x) < eps) {
            break;
        }
        x_prev = x;
        x = x_next;
        fx_prev = fx;
        fx = f(x, a, b);
        dfx = df(x, a, b);
        ddfx = ddf(x, a, b);
        if (iterations<100 and x>=x0 and x<=x1)
        {
            iterations++;
        }
        else {
            cout << "Root nnot found\n";
            return 0;
        }
    }

    return x;
}

int main() {
    double a, b, x0, x1, eps;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter epsilon: ";
    cin >> eps;
    
    while (1) {
        cout << "Enter x0: ";
        cin >> x0;
        cout << "Enter x1: ";
        cin >> x1;
        double x = combinedMethod(a, b, x0, x1, eps);
        cout << "x = " << x << ", f(x) = " << f(x, a, b) << endl;
    }


    return 0;
}
