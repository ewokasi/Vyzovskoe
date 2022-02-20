
#include <math.h>
#include <iostream>
#include <string.h>


float z1(int angle) // формула 1
{
    float pi = 3.1415;
    double rads = angle * pi / 180;  //расчет радианной меры угла

    return pow(cos((3 * pi/ 8)  - rads / 4), 2) - pow(cos((11* pi / 8)  + rads / 4), 2); //формула 1
}



float z2(int angle) //формула 2
{   
    float pi = 3.1415;
    double rads = angle * pi / 180;  //расчет радианной меры угла

    return ((sqrt(2) / 2) * sin(rads / 2));  //формула 2
}

int main()
{
    int angle ;

    printf("Enter the angle you want to calculate\n");  //общение с пользователем
    while (true)
    {
        std::cin >> angle;
        if (isdigit(angle)) {
            break;
        }
    }
    
    printf("You've enetred: ", angle, "\n", "z1 result: ");
    printf("%.2f", z1(angle));
    printf("z2 result: ");
    printf("%.2f", z2(angle));
   
    return 0;
}