#pragma once
#ifndef guests_h
#define guests_h
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// Класс, представляющий постояльца отеля
class Guest {
public:
    Guest(string passNum, string fullName, int birthYear, string address, string purpose)
        : passportNumber(passNum), fullName(fullName), birthYear(birthYear), address(address), purpose(purpose) {}

    string passportNumber;  // Номер паспорта
    string fullName;        // ФИО
    int birthYear;          // Год рождения
    string address;         // Адрес
    string purpose;         // Цель прибытия
};

// Класс, представляющий элемент хеш-таблицы
class Entry {
public:
    Guest* guest;   // Указатель на объект типа Guest
    bool deleted;   // Флаг, показывающий, был ли элемент удален

    Entry() : guest(nullptr), deleted(false) {}
};

// Класс, представляющий хеш-таблицу
class HashTable {
public:
    HashTable() : size(10), count(0), table(size) {}

    // Функция для добавления элемента в хеш-таблицу
    void put(string passNum, string fullName, int birthYear, string address, string purpose) {
        if (count >= size / 2) {
            resize();
        }

        int hash = getHash(passNum);  // Вычисляем хеш-код
        while (table[hash].guest != nullptr && table[hash].guest->passportNumber != passNum) {
            hash = (hash + 1) % size;
        }

        if (table[hash].guest == nullptr) {
            table[hash].guest = new Guest(passNum, fullName, birthYear, address, purpose);
            count++;
        }
        else {
            table[hash].guest->fullName = fullName;
            table[hash].guest->birthYear = birthYear;
            table[hash].guest->address = address;
            table[hash].guest->purpose = purpose;
        }
    }

    // Функция для получения элемента из хеш-таблицы
    Guest* get(string passNum) {
        int hash = getHash(passNum);  // Вычисляем хеш-код
        while (table[hash].guest != nullptr) {
            if (table[hash].guest->passportNumber == passNum) {
                return table[hash].guest;
            }
            hash = (hash + 1) % size;
        }
        return nullptr;
    }

    // Функция для удаления элемента из хеш-таблицы
    void remove(string passNum) {
        int hash = getHash(passNum);  // Вычисляем хеш-код
        while (table[hash].guest != nullptr) {
            if (table[hash].guest->passportNumber == passNum) {
                table[hash].deleted = true;
                count--;
                return;
            }
            hash = (hash + 1) % size;
        }
    }

    void show( string passport) {
        Guest* guest = get(passport);
        if (guest != nullptr) {
            cout << "ФИО: " << guest->fullName << endl;
            cout << "Год рождения: " << guest->birthYear << endl;
            cout << "Адрес: " << guest->address << endl;
            cout << "Цель прибытия: " << guest->purpose << endl;
        }
        else
        {
            cout << "Error, try again\n";
        }
    }
    void show_by_name(string FIO) {
        for (auto i : table) {
            if (i.guest != nullptr ) {
                if (FIO != i.guest->fullName) continue;
                cout << "ФИО: " << i.guest->fullName << endl;
                cout << "Год рождения: " << i.guest->birthYear << endl;
                cout << "Адрес: " << i.guest->address << endl;
                cout << "Цель прибытия: " << i.guest->purpose << endl;
            }
        }
       
    }
    void show_all() {
        for (auto i : table) {
            if (i.guest != nullptr && i.deleted==false) {
                cout << "\nФИО: " << i.guest->fullName << endl;
                cout << "Год рождения: " << i.guest->birthYear << endl;
                cout << "Адрес: " << i.guest->address << endl;
                cout << "Цель прибытия: " << i.guest->purpose << "\n\n";
            }
        }
    }
    void remove_all() {
        for (auto i : table) {
            if (i.guest != nullptr) {
                i.deleted = true;
                count--;
            }
        }

    }


private:
    int size;
    int count;          // Количество элементов в хеш-таблице
    vector<Entry> table;    // Массив элементов типа Entry

    // Функция для вычисления хеш-кода
    int getHash(string passNum) {
        int hash = 0;
        for (char c : passNum) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

    // Функция для изменения размера хеш-таблицы
    void resize() {
        size *= 2;
        vector<Entry> newTable(size);
        for (auto& entry : table) {
            if (entry.guest != nullptr && !entry.deleted) {
                int hash = getHash(entry.guest->passportNumber);
                while (newTable[hash].guest != nullptr) {
                    hash = (hash + 1) % size;
                }
                newTable[hash].guest = entry.guest;
            }
        }
        table = newTable;
    }

    
    // Размер хеш-таблицы
};
//
//int main()
//{
//    setlocale(LC_ALL, "RUS");
//    HashTable hotel;
//    // Добавление элементов
//    hotel.put("1234-567890", "Иванов Иван Иванович", 1980, "Москва, ул. Пушкина, д.1", "Отдых");
//    hotel.put("2345-678901", "Петров Петр Петрович", 1990, "Санкт-Петербург, ул. Ломоносова, д.2", "Работа");
//    hotel.put("3456-789012", "Сидоров Сидор Сидорович", 1975, "Казань, ул. Баумана, д.3", "Отдых");
//
//    // Получение элемента
//    Guest* guest = hotel.get("1234-567890");
//    if (guest != nullptr) {
//        cout << "ФИО: " << guest->fullName << endl;
//        cout << "Год рождения: " << guest->birthYear << endl;
//        cout << "Адрес: " << guest->address << endl;
//        cout << "Цель прибытия: " << guest->purpose << endl;
//    }
//    else {
//        cout << "Постоялец не найден" << endl;
//    }
//
//    // Удаление элемента
//    hotel.remove("2345-678901");
//
//    return 0;
//
//}

#endif
