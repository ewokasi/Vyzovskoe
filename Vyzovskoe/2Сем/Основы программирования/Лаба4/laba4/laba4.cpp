
#include <iostream>
#include <string>

double fill() {
    std::string input;
    while (true)    //проверка введенного числа
    {   
        
        bool error = 0;
        std::cin >> input;
        for (int i = 0; i < input.size(); i++) {

            if ((isdigit(input[i]) == 0 && input[i]!='.' &&input[i]!='-')) {
                error = 1;
                break;
            }

        }
        if (error == 1) {
            printf("Enter value without letters\n");

        }
        else
        {
            break;
        }

    }
    
    return stod(input);

}

void solve(double a, double b, double c, double xn, double xk, double xd) {
    for (double i = xn; i <= xk; i += xd) {
        double f;
        if (c != 0 and i < 5) {
            f = -a * i * i - b;
        }
        else if (i > 5 and c == 0) {
            f = (i - a) / i;
        }
        else {
            f = (-i) / c;
        }
        std::cout <<"x=" << i << ": F=" << f << "\n";
    }

}

int main()
{   
    double a, b, c;
    double xn, xk, xd;
    std::cout << "enter a, b, c, x0, x1, xd\n";
    a = fill();
    b = fill();
    c = fill();
    xn = fill();
    xk = fill();
    xd = fill();
    solve(a, b, c, xn, xk, xd);
    
    
    
    
}
