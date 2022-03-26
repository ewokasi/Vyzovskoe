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
				cout <<"sum of minus in "<<i<<" string: " << res << endl;
			}
		}
	}
}

int main()
{
	cout << "Enter N\n";
	int n;
	cin >> n;

	double** arr = new double*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[n];
	}

	for (int i = 0; i < n; i++)
	{	
		int c = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			
		}
		
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
			cout << endl;
	}
		
	
	search(arr, n);
	sum_m(arr, n);
	delete [] arr;

	// Для обнаружения утечек памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

}

