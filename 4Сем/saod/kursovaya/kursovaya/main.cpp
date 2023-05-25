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
	// ���������� ���������
	booking.add("1234-567890", "595A", "16.05.23", "19.05.23");
	booking.add("3017-123456", "132A", "11.05.23", "19.06.23");
	booking.add("3434-323232", "1223B", "10.05.23", "30.08.23");
	visitors.put("1234-567890", "������_����_��������", 1980, "������, ��. �������, �.1", "�����");
	visitors.put("3017-123456", "������_����_��������", 1990, "�����-���������, ��. ����������, �.2", "������");
	visitors.put("3434-323232", "�������_�����_���������", 1975, "������, ��. �������, �.3", "�����");

	while (1)
	{
		std::cout << "-------------------------���� ���������� -------------------------\n";
		std::cout << "1) ����������� ������ ����������                                  |\n";
		std::cout << "2) �������� ������ � ����������                                   |\n";
		std::cout << "3) �������� ���� ������������������ �����������                   |\n";
		std::cout << "4) ������� ������ � �����������                                   |\n";
		std::cout << "5) ����� ���������� �� ������ ��������                            |\n";
		std::cout << "6) ����� ���������� �� ���                                        |\n";
		std::cout << "7) ���������� ������ ������������ ������                          |\n";
		std::cout << "8) �������� �������� � ����������� ������                         |\n";
		std::cout << "9) �������� ���� ��������� ����������� �������                    |\n";
		std::cout << "10) ������� ������ � ����������� �������                          |\n";
		std::cout << "11) ����� ������������ ������ �� ������� ������������ ������     |\n";
		std::cout << "12) ����� ������������ ������ �� ���������� ��������������        |\n";
		std::cout << "13) ����������� �������� ����������                               |\n";
		std::cout << "14) ����������� ��������� ����������                              |\n";
		std::cout << "------------------------------------------------------------------\n";
		int var;
		std::cin >> var;

		
		
		

		switch (var)
		{
		case 1:
			std::cout << "������� �������: ";
			std::cin >> passport;
			std::cout << "������� ���: ";
			std::cin >> FIO;
			std::cout << "������� ��� ��������: ";
			std::cin >> year;
			std::cout << "������� �����: ";
			std::cin >> city;
			std::cout << "������� ���� ������: ";
			std::cin >> purpose;
			visitors.put(passport, FIO, year, city, purpose);
			std::cout << "�������.\n";
			break;

		case 2:
			std::cout << "������� �������: ";
			std::cin >> passport;
			visitors.remove(passport);
			std::cout << "�������.\n";
			break;

		case 3:
			visitors.show_all();
			break;

		case 4:
			std::cout << "������� �������: ";
			std::cin >> passport;
			visitors.remove(passport);
			std::cout << "�������.\n";
			break;

		case 5:
			std::cout << "������� �������: ";
			std::cin >> passport;
			visitors.show(passport);
			break;

		case 6:
			std::cout << "������� ���: ";
			
			std::cin>>FIO;
			visitors.show_by_name(FIO);
			std::cout << "�������.\n";
			break;

		case 7:
			std::cout << "������� �����: ";
			//int k, unsigned char t = 'A', int cap = 2, string te = "", bool b = 1
			std::cin >> num;
			std::cout << "������� �����: ";
			std::cin >> let;
			std::cout << "������� ���������������: ";
			std::cin >> capacity;
			std::cout << "������� ������� ����� _: ";
			std::cin >> technic;
			std::cout << "������� 1 ��� 0 �� ������� ������: ";
			std::cin >> bathroom;
			insert(rooms, num, let, capacity, technic, bathroom);
			std::cout << "�������.\n";

			break;

		case 8:
			std::cout << "������� �����: ";
			std::cin >> num;
			remove(rooms, num);
			std::cout << "������.\n ";
			break;

		case 9:
			walk(rooms);
			std::cout << "\n������.\n ";
			break;

		case 10:
			rooms = new node(5, 'A');
			break;

		case 11:
			std::cout << "������� �����: ";
			std::cin >> num;
			serch(rooms, num);
			break;

		case 12:
			std::cout << "������� ������������: ";
			std::cin >> technic;
			find_by_technic(rooms, technic);
			break;

		case 13:
			std::cout << "������� �����: ";
			std::cin >> room;
			std::cout << "������� ������� ����������: ";
			std::cin >> passport;
			std::cout << "������� ���� ���������: ";
			std::cin >> goesin;
			std::cout << "������� ���� ���������: ";
			std::cin >> goesout;
			booking.add(passport, room, goesin, goesout);
			break;

		case 14:
			std::cout << "������� �����: ";
			std::cin >> room;
			booking.remove_by_room(room);
			std::cout << "�������\n";
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