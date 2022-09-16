// laba8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include<string.h>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int solution (string path)
{
    setlocale(LC_ALL, "rus");
    ifstream file;
    ofstream file2;
    file2.open("C:\\Users\\kosty\\Documents\\GitHub\\Vyzovskoe\\2Сем\\Основы программирования\\laba8\\doklad2.txt");
    string s;
    int c=0;
    file.open(path);
    for (file >> s; file.is_open()&& !file.eof(); file >> s) {

        if ((s.length() <= 4 && s != " " && s != "\n" && s != "-") || (s.length() == 5 && (s[4] == '.' || s[4] == ','))) {
            c++;
            file2 << s << endl;
        
        };
    }
    if (file.is_open() == 0)cout << "FileNotFound" << endl;
    file.close();
    file2.close();
    return c;
}

int solution2() 
{
    char line[33];

    FILE* pFile= fopen("C:\\Users\\kosty\\Documents\\GitHub\\Vyzovskoe\\2Сем\\Основы программирования\\laba8\\doklad.txt", "r");
    FILE* pFile2 = fopen("C:\\Users\\kosty\\Documents\\GitHub\\Vyzovskoe\\2Сем\\Основы программирования\\laba8\\doklad3.txt", "w");
    if (pFile!=NULL)
    {
        while (fscanf(pFile, "%s", line)) {
            
            if (feof(pFile)) {
                break;
            }

            int len = 0;
            for (char i : line) {
                
                if (i != '\0' && i != ' ' && i != '.' && i != ',') {
                    len++;
                 
                }
                else
                {
                    if (len < 5 && len!=0) {
                        
                        fprintf(pFile2, "%s", line);
                        fprintf(pFile2, "%s", "\n");
                    }
                    len = 0;
                    break;
                }

            }
            

        }
        
        fclose(pFile); fclose(pFile2);
       
    }
    else
    {
        cout << "FileNotFound" << endl;
    }


    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    solution("C:\\Users\\kosty\\Documents\\GitHub\\Vyzovskoe\\2Сем\\Основы программирования\\laba8\\doklad.txt");
    solution2();
}

