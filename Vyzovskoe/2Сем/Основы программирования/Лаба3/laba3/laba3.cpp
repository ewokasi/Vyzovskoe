
#include <iostream>
#include <string>
#include <bitset>
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

int prepack(int n) {
    int b = 0;
    while (b <= n) {        //ввод приемлемых значений
        cout << "Enter decade num lower then "<<n<<"\n";
        b = fill();
        if (b <= n) {
            break;
        }

    }
    return b;
}

int main()
{  
    unsigned short int s{}, d{}, f{}, b{}, x;

    s = prepack(7); //заполняем ячейки
    d = prepack(1);
    f = prepack(1);
    b = prepack(255);


    x = b;          //пакуем все данные
    x = 0 << 8 | x;
    x = f << 9 | x;
    x = 0 << 10 | x;
    x = d << 11 | x;
    x = s << 13 | x;
    cout <<hex << x << endl;
    cout << bitset<16>{x};
}
