//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#ifdef _DEBUG
//#ifndef DBG_NEW
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#define newDBG_NEW
//#endif
//#endif

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

			if ((isdigit(input[i]) == 0 )) {
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

	return std::stoi(input);
}


void muta(char str[],const int str_len, const int len) {

	char res[200];

	for (int i = 0; i < len / 2 + len % 2; i++) res[i] = '_';

	for (int i = 0; i < str_len; i++) res[i+ len / 2] = str[i];

	for (int i = 0; i < len / 2; i++) res[i + len / 2 +str_len] = '_';

	res[len + str_len] = '\0';

	for (int i = 0; i < len + str_len-len%2; i++)cout << res[i];
	
}

int main()
{
	setlocale(LC_ALL, "rus");
	string s;
    char str[100];
    int len;

    cout << "Enter the string you want to insert among '___': ";
	
	cin >> s;
	int lens = s.length();
	
	for (int i = 0; i < lens; i++) str[i] = s[i];

	str[lens] = '\0';
	cout << "You've entered: ";
	for (int i = 0; i < lens; i++) cout<<str[i];
	cout << endl;

	cout << "Enter the length of ___: ";
	len = fill();
	muta(str, lens, len);
	cout << endl;
}
