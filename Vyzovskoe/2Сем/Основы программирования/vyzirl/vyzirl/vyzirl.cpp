
#include <iostream>

using namespace std;

void tcount(int * arr[], double * max, int * c, double *max_neg) 
{
	
	bool flag = 0;
	int counter = 0;
	double max_n=0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] > *max)
			{
				*max = arr[i][j];
			}

			if (arr[i][j] < 0)
			{
				if (flag == 0)
				{
					max_n = arr[i][j];
					flag = 1;
				}


				if (arr[i][j] > max_n)
				{
					max_n = arr[i][j];
				}
			}
				if (arr[i][j] == 0)
				{
					counter++;
				}
			
		}
	}
	*c = counter;
	*max_neg = max_n;
	
}


int** input()
{
	int** arr = 0;
	arr = new int* [5];

	for (int i = 0; i < 5; i++)
	{
		arr[i] = new int[6];

		for (int j = 0; j < 6; j++)
		{
			
			cin >> arr[i][j];
		}
	}

	return arr;
}

void output(int *arr[]) 
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;

	}
}

int main()
{	
	setlocale(LC_ALL, "Russian");

	cout << "Enter array A" << endl;
	int **A = input();

	cout << "Enter array B: " << endl;
	int** B = input();


	cout<< endl << "Array A:" << endl;
	output(A);
		
	cout <<endl<< "Array B: " << endl;	
	output(B);

	int c=0;
	double max = 0;
	double max_neg;

	int* pc = &c;
	double* pmax = &max;
	double* pmax_neg = &max_neg;
	tcount(A, pmax, pc, pmax_neg);

	cout << "Наибольшее отрицательное значение, Наибольшее значетние, Количество нулевых для массива A: ["<<*pmax_neg<<", "<<*pmax<<", "<<*pc<<"]" << endl;
	tcount(B, pmax, pc, pmax_neg);
	cout << "Наибольшее отрицательное значение, Наибольшее значетние, Количество нулевых для массива B: [" << *pmax_neg << ", " << *pmax << ", " << *pc << "]" <<endl;

}

