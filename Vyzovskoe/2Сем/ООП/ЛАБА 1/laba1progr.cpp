
#include <math.h>
#include <iostream>
#include <String>


double z1(double angle) // формула 1
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
    std::string input;
    double angle;
    

    printf("Enter the angle you want to calculate\n");  //общение с пользователем
    std::cin >> input;
    angle = std::stod(input);

    printf("You've enetred: ");
    printf(angle);
    printf("\n", "z1 result: ");
    printf("%.2f", z1(angle));
    printf(" z2 result: ");
    printf("%.2f", z2(angle));

    return 0;
}