
#include <random>
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


int* gen_array(int n) 
{
    random_device rd;
    mt19937 gen(rd());
    
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int rand_num = gen();
        int pos = gen()%2;
        if (pos == 1)
        {
            arr[i] = rand_num % n/2+1;
        }
        else
        {
            arr[i] = -rand_num % n/2-1;
        }
    }

    return arr;
}

void show_array(int arr[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int* decrease_by_two(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] - 2;
    }

    return arr;
}


int count_pos(int b)
{
    if (b >= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{   
    cout << "Enter len "<<endl;
    int n = fill();

    int* arr = gen_array(n);
    cout << "Your array: ";
    show_array(arr, n);

    cout << "Enter:\n1 if you want to decrease all elementts by 2\n2 if you want to count positive elements\n";

    while (1) {
        int input = fill();
        ;
        if (input == 1)
        {
            decrease_by_two(arr, n);
            cout << "Decreased array: ";
            show_array(arr, n);
            cout << endl;
        }
        else if (input == 2) {
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (count_pos(arr[i]) == 1) {
                    c++;
                }
            }
            cout << "pos " << c << endl;
        }
        else {
            break;
        }
    }
}
