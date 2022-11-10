#include<String>
#include <iostream>

std::string check()
{

    while (true)    //проверка введенного числа
    {   
        std::string input;
        bool error = 0;
        std::cin >> input;
        for (int i = 0; i < input.size(); i++) {

            if ((isdigit(input[i]) == 0 && input[i] != ',' && input[i] != '-')) {
                error = 1;
                break;
            }

        }
        if (error == 1) {
            printf("Enter value without letters\n");

        }
        else
        {
            return input;
            break;
        }

    }
    
}

int main()
{   
    setlocale(LC_ALL, "Russian");

    double x; //Объявление переменыых
    double y;
    

    std::cout << "Enter x\n";
    x = stod(check());

    std::cout << "Enter y\n";
    y = stod(check());

    
    if (x >= 0 && y >= 0 && (x * x + y * y <= 1) || x >= -1 && y >= -1&&x<0&&y<0) {//проверка условий
        std::cout << "Точка принадлежит графику\n";
    }
    else {
        std::cout << "Точка лежит вне графика\n";
    }

   
}