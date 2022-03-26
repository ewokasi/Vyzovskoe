
#include <iostream>
#include <string>
using namespace std;

double fill() {
    std::string input;
    while (true)    //проверка введенного числа
    {

        bool error = 0;
        std::cin >> input;
        for (int i = 0; i < input.size(); i++) {

            if ((isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-')) {
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

    return stoi(input);
}


int main()
{  
    unsigned short int s{}, d{}, f{}, b{}, x;

    while (s <= 7) {        //ввод приемлемых значений
        cout << "Enter decade num lower then 8\n";
        s = fill();
        if (s <= 7) {
            break;
        }
        
    }
    while (d <= 1) {        //ввод приемлемых значений
        cout << "Enter decade num lower then 2\n";
        d = fill();
        if (d <= 1) {
            break;
        }
    }
    while (f <= 1) {        //ввод приемлемых значений
        cout << "Enter decade num lower then 2\n";
        f = fill();
        if (f <= 1) {
            break;
        }
    }
    while (b <= 255) {        //ввод приемлемых значений
        cout << "Enter decade num lower then 256\n";
        b = fill();
        if (b <= 255) {
            break;
        }
    }
    x = b;          //пакуем все данные
    x = 0 << 8 | x;
    x = f << 9 | x;
    x = 0 << 10 | x;
    x = d << 11 | x;
    x = s << 13 | x;
    cout <<hex << x << endl;
}
