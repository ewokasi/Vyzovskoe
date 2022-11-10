#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

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
#include <windows.h>
#include <ConsoleApi2.h>
#include <fstream>
using namespace std;

struct NumList {
	int num;
	NumList* next;
};

//вывод элементов списка на экран
void ShowList(NumList* head)
{
	NumList* p = head;
	while (p != NULL)
	{
		cout << p->num << ' ';
		p = p->next;
	}
}

// Добавление элемента в конец списка
void AddElem(NumList** head, int value)
{
	NumList* cur = *head;
	NumList* p = new NumList;
	p->num = value;
	//проверка, является ли список пустым
	if (cur == NULL)
	{
		p->next = NULL;
		*head = p;
	}
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = p;
		p->next = NULL;
	}
}


//очистка памяти
void FreeList(NumList** head)
{
	NumList* cur = NULL;
	while ((*head)->next)
	{
		cur = *head;
		*head = (*head)->next;
		delete cur;
	}
	delete* head;
}


int main() {
	char filename[256]= { "C:\\Users\\kosty\\OneDrive\\Рабочий стол\\1.txt" };
	SetConsoleOutputCP(1251);
	NumList* list = NULL;

	cout << "Введите имя файла:";
	
	
	if (filename != NULL) {

		fstream f;
		f.open(filename);
		if (!f.is_open()) {
			cout << "ошибка чтения файла";
			return 1;

		}
		int a;
		while (!f.eof()) {
			f >> a;
			cout << a << endl;
			AddElem(&list, a);
		}
		cout << "My number list: ";
		ShowList(list);
		ShowList(list);
		FreeList(&list);

	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;

}

