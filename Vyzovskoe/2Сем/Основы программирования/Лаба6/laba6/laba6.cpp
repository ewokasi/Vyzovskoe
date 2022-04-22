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
#include<string>

using namespace std;


void search(double* arr[], int n) {
	for (int i = 0; i < n; i++) {
		
		int c = 0;
		for (int q = 0; q < n; q++) {
			if (arr[i][q] == arr[q][i]) {
				c++;
				if (c == n) cout << i <<" is k" << endl;
			}
		}
	}
	
}

void sum_m(double* arr[], int n){
	for (int i = 0; i < n; i++) {
		double res=0;
		bool flag = 0;
		for (int q = 0; q < n; q++) {
			if (arr[i][q] < 0) {
				flag = 1;
			}
			if (flag == 1) {
				for (int q=0; q < n; q++) {
					res = res + arr[i][q];
				}
				cout <<"sum with minus in "<<i<<" string: " << res << endl;
				res = 0;
				flag = 0;
				break;
			}
		}
	}
	
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
	
	return std::stod(input);
}

int main()
{
	
	int n= -1;
	while (n <= 0) {
		cout << "Enter N\n";
		n = fill();
	}
	

	double** arr = new double*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[n];
	}
	cout << "Fill all your strings\n";
	for (int i = 0; i < n; i++)
	{	
		int c = 0;
		for (int j = 0; j < n; j++)
		{
			cout << "enter [" << i << "] [" << j << "] element: ";
			arr[i][j]=fill();
			
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int q = 0;q < n; q++) {
			cout << arr[i][q] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	search(arr, n);
	sum_m(arr, n);

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	// Для обнаружения утечек памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

}

