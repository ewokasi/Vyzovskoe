
#include <math.h>
#include <iostream>
#include <String>


double z1(const double angle) // формула 1
{
    float pi = 3.1415;
    double rads = angle * pi / 180;  //расчет радианной меры угла

    return pow(cos((3 * pi / 8) - rads / 4), 2) - pow(cos((11 * pi / 8) + rads / 4), 2); //формула 1
}



double z2(double angle) //формула 2
{
    float pi = 3.1415;
    double rads = angle * pi / 180;  //расчет радианной меры угла

    return ((sqrt(2) / 2) * sin(rads / 2));  //формула 2
}

int main()
{   
    setlocale(LC_ALL, "Russian");
    std::string input;
    double angle;
    

    printf("Enter the angle you want to calculate\n");  //общение с пользователем

    while (true)    //проверка введенного числа
    {
        bool error = 0;
        std::cin >> input;
        for (int i = 0; i < input.size(); i++) {

            if ((isdigit(input[i]) == 0)) {
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
    
    angle = std::stod(input);

    printf("You've enetred: "); //вычисления
    printf("%.2f", angle);
    
    printf("\n", "z1 result: ");
    printf("%.9f", z1(angle));
    printf(" z2 result: ");
    printf("%.9f", z2(angle));

  
}