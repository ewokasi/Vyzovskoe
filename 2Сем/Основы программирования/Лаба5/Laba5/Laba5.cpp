#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif

#include <iostream>
#include <string>

using namespace std;

int max_i(double arr[], int n) { //поиск индекса максимального элемента
    double max = 0;
    int max_i;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_i = i;
        }
    }
    return max_i;
}

double nul(double arr[], int n) { //поиск произведения между нулями
    int f = -1;
    int s = -1;
    for (int i = 0; i < n; i++) {
        
        if (arr[i] == 0 && f==-1) {
            f = i;
        }
        else if (arr[i] == 0 && f != -1) {
            s = i;
            break;
        }
    }
   
    double res = 1;

    for (int i = f+1; i < s; i++) {
        res = res * arr[i];
    }
    if (s != -1) {
        return res;
    }
    else {
        return 0;
    }
    }
 
void mut(double arr[],const int n) {//переставление элементов
    
    double* arr1 = new double[n / 2 +(n%2)];
    double* arr2 = new double[n / 2];
    double* arr3 = new double[n];
    int q = 0;


    for (int i = 0; i < n; i = i + 1) {
        if (i % 2 == 0) {
            arr1[q] = arr[i];
            q++;
        }
    }

    q = 0;
    for (int i = 1; i < n; i = i + 1) {
        if (i % 2 == 1) {
            arr2[q] = arr[i];
            q++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i < n / 2 + (n % 2)) {
            arr3[i] = arr1[i];
        }
        else
        {
            arr3[i] = arr2[i - n / 2 - (n % 2)];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr3[i]<<" ";
    }
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
}

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

    return stod(input);

}


int main()
{
    
    double n;
    n = 0;
    while(n==0 || n<0 ){
        std::cout << "Enter N\n";
        n = fill();
    }
    

    std::cout << "Enter arr 1 by 1\n";
   
    double *arr = new double[n]; //динамическое создание массива
    
    for (int i = 0; i < n; i++) { //заполнение массива
         arr[i]=fill();

    }
    cout << max_i(arr, n)<<" Max elem" << endl; //результат
    cout << nul(arr, n)<<"null multipl" << endl;
    cout << "array mixing ";
    mut(arr, n);
    delete [] arr; //очистка

    // Для обнаружения утечек памяти
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();
}