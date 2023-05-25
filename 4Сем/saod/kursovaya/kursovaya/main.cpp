#include "rooms.h"
#include "guests.h"
#include "booking.h"
#include<windows.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	node* rooms = new node(5, 'A');
	for (int i = 0; i < 11; i+=2) {
		insert(rooms, i);
		
	}
	//guests
	string passport;
	string FIO;
	int year;
	string city;
	string purpose;

	//rooms
	int num;
	string technic;
	char let;
	int capacity;
	bool bathroom;

	//booking
	LinkedList booking;
	string room, goesin, goesout;
	HashTable visitors;
	// Добавление элементов
	booking.add("1234-567890", "595A", "16.05.23", "19.05.23");
	booking.add("3017-123456", "132A", "11.05.23", "19.06.23");
	booking.add("3434-323232", "1223B", "10.05.23", "30.08.23");
	visitors.put("1234-567890", "Иванов_Иван_Иванович", 1980, "Москва, ул. Пушкина, д.1", "Отдых");
	visitors.put("3017-123456", "Петров_Петр_Петрович", 1990, "Санкт-Петербург, ул. Ломоносова, д.2", "Работа");
	visitors.put("3434-323232", "Сидоров_Сидор_Сидорович", 1975, "Казань, ул. Баумана, д.3", "Отдых");

	while (1)
	{
		std::cout << "-------------------------Меню управления -------------------------\n";
		std::cout << "1) регистрация нового постояльца                                  |\n";
		std::cout << "2) удаление данных о постояльце                                   |\n";
		std::cout << "3) просмотр всех зарегистрированных постояльцев                   |\n";
		std::cout << "4) очистка данных о постояльцах                                   |\n";
		std::cout << "5) поиск постояльца по номеру паспорта                            |\n";
		std::cout << "6) поиск постояльца по ФИО                                        |\n";
		std::cout << "7) добавление нового гостиничного номера                          |\n";
		std::cout << "8) удаление сведений о гостиничном номере                         |\n";
		std::cout << "9) просмотр всех имеющихся гостиничных номеров                    |\n";
		std::cout << "10) очистку данных о гостиничных номерах                          |\n";
		std::cout << "11) поиск гостиничного номера по «номеру гостиничного номера»     |\n";
		std::cout << "12) поиск гостиничного номера по фрагментам «Оборудования»        |\n";
		std::cout << "13) регистрацию вселения постояльца                               |\n";
		std::cout << "14) регистрацию выселения постояльца                              |\n";
		std::cout << "------------------------------------------------------------------\n";
		int var;
		std::cin >> var;

		
		
		

		switch (var)
		{
		case 1:
			std::cout << "Введите Паспорт: ";
			std::cin >> passport;
			std::cout << "Введите ФИО: ";
			std::cin >> FIO;
			std::cout << "Введите год рождения: ";
			std::cin >> year;
			std::cout << "Введите Адрес: ";
			std::cin >> city;
			std::cout << "Введите цель визита: ";
			std::cin >> purpose;
			visitors.put(passport, FIO, year, city, purpose);
			std::cout << "Успешно.\n";
			break;

		case 2:
			std::cout << "Введите Паспорт: ";
			std::cin >> passport;
			visitors.remove(passport);
			std::cout << "Успешно.\n";
			break;

		case 3:
			visitors.show_all();
			break;

		case 4:
			std::cout << "Введите Паспорт: ";
			std::cin >> passport;
			visitors.remove(passport);
			std::cout << "Успешно.\n";
			break;

		case 5:
			std::cout << "Введите Паспорт: ";
			std::cin >> passport;
			visitors.show(passport);
			break;

		case 6:
			std::cout << "Введите ФИО: ";
			
			std::cin>>FIO;
			visitors.show_by_name(FIO);
			std::cout << "Успешно.\n";
			break;

		case 7:
			std::cout << "Введите Номер: ";
			//int k, unsigned char t = 'A', int cap = 2, string te = "", bool b = 1
			std::cin >> num;
			std::cout << "Введите Букву: ";
			std::cin >> let;
			std::cout << "Введите Вместительность: ";
			std::cin >> capacity;
			std::cout << "Введите Технику через _: ";
			std::cin >> technic;
			std::cout << "Введите 1 или 0 за наличие ванной: ";
			std::cin >> bathroom;
			insert(rooms, num, let, capacity, technic, bathroom);
			std::cout << "Успешно.\n";

			break;

		case 8:
			std::cout << "Введите Номер: ";
			std::cin >> num;
			remove(rooms, num);
			std::cout << "Упешно.\n ";
			break;

		case 9:
			walk(rooms);
			std::cout << "\nУпешно.\n ";
			break;

		case 10:
			rooms = new node(5, 'A');
			break;

		case 11:
			std::cout << "Введите Номер: ";
			std::cin >> num;
			serch(rooms, num);
			break;

		case 12:
			std::cout << "Введите Оборудование: ";
			std::cin >> technic;
			find_by_technic(rooms, technic);
			break;

		case 13:
			std::cout << "Введите Номер: ";
			std::cin >> room;
			std::cout << "Введите паспорт постояльца: ";
			std::cin >> passport;
			std::cout << "Введите дату заселения: ";
			std::cin >> goesin;
			std::cout << "Введите дату выселения: ";
			std::cin >> goesout;
			booking.add(passport, room, goesin, goesout);
			break;

		case 14:
			std::cout << "Введите Номер: ";
			std::cin >> room;
			booking.remove_by_room(room);
			std::cout << "Успешно\n";
			break;

		case 15:
			booking.print();
			break;
		case 16:
			show(rooms);
			break;
		default:
			break;
		}
	}
	
	
	
	    return 0;
}