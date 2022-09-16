
#include <iostream>

using namespace std;

int check(int * arr[]) 
{

	int pos = 0;
	int neg = 0;

	//считаем количесвто элементов
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			if (arr[i][j] < 0) {
				neg++;
			}
			else {
				pos++;
			}
		}
	}

	if (pos > neg) {
		return 1;
	}
	else
	{
		return 0;
	}

}

int** input()
{
	int** arr = 0;
	arr = new int* [5];

	for (int i = 0; i < 5; i++)
	{
		arr[i] = new int[5];

		for (int j = 0; j < 5; j++)
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
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;

	}
}

int main()
{	
	setlocale(LC_ALL, "Russian");

	cout << "Enter array S" << endl;
	int **S = input();

	cout << "Enter array X: " << endl;
	int** X = input();


	cout<< endl << "Array S:" << endl;
	output(S);
		
	cout <<endl<< "Array X: " << endl;	
	output(X);


	bool A, B;
	
	A = check(S);
	B = check(X);
	
	
	cout<< endl << "A:" << A << " B:" << B << endl;
}

