
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

std::string solve(double a, double b, double c, double i) {

     double f;
     if (i != 0) {
         if (c != 0 and i < 5) {
             f = -a * i * i - b;
         }
         else if (i > 5 and c == 0) {
             f = (i - a) / i;
         }
         else {
             f = (-i) / c;
         }
         return std::to_string(f);
     }
     else
     {
         return "err";
     }
 }


int main()
{   
    setlocale(LC_ALL, "rus");
    double a, b, c;
    double xn, xk, xd;
    std::cout << "enter a, b, c, x0, x1, xd\n";
    a = fill();
    b = fill();
    c = fill();
    xn = fill();
    xk = fill();
    xd = fill();

    if (xn > xk) {
        double c = xn;
        xn = xk;
        xk = c;
    }
    if (xd < 0)xd = -xd;


    for (double i = xn; i <= xk; i = i + xd) {
        std::cout << "x: " << i << " F=" << solve(a, b, c, i) << std::endl;
    }

     
}
