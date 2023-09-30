#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
struct Bludo
{
	Bludo* Prev;
	char KategBludo[100];
	char NazvanieBludo[100];
	int VesBludoGr;
	int StoumostBludoRub;
};
Bludo* Head;
Bludo* Tail;

void Push()
{
	Bludo* temp = new Bludo;
	temp->Prev = NULL;
	cout << "Введите Категорию Блюда:" << endl;
	cin >> (temp->KategBludo);

	cout << "Введите Название Блюда:" << endl;
	cin >> (temp->NazvanieBludo);

	cout << "Введите Вес Блюда в граммах:" << endl;
	cin >> (temp->VesBludoGr);

	cout << "Стоимость Блюда в рублях:" << endl;
	cin >> (temp->StoumostBludoRub);
	
	if (Head != NULL)
	{
		temp->Prev = Head;
		Head = temp;

	}
	else
	{
		temp->Prev = NULL;
		Head = temp;
	}
}

void Print()
{
	Bludo* temp = Head;
	while (temp != NULL)
	{
		cout << "Категория Блюда - ";
		puts(temp->KategBludo);
		cout << "Название Блюда - ";
		puts(temp->NazvanieBludo);
		cout << "Вес Блюда в граммах - " << temp->VesBludoGr << endl;
		cout << "Стоимость Блюда в рублях - " << temp->StoumostBludoRub << endl;
		
		temp = temp->Prev;
	}
}

void FromFileToList()
{
	char BUFFER[100];
	char VesBludoGrBUFFER[100];
	char StoumostBludoRubBUFFER[100];
	ifstream file("Bludo.txt");

	while (!file.eof()) {
		Bludo* temp = new Bludo;
		temp->Prev = NULL;

		file.getline(temp->KategBludo, 100);
		file.getline(temp->NazvanieBludo, 100);
		
		file.getline(VesBludoGrBUFFER, 100);
		int value = atoi(VesBludoGrBUFFER);
		temp->VesBludoGr = value;
		file.getline(StoumostBludoRubBUFFER, 100);
		int value1 = atoi(StoumostBludoRubBUFFER);
		temp-> StoumostBludoRub = value1;
		
		if (Head != NULL)
		{
			temp->Prev = Head;
			Head = temp;

		}
		else
		{
			temp->Prev = NULL;
			Head = temp;
		}
	}
	file.close();
}

void ListToFile()
{
	Bludo* temp = Head;
	ofstream fout("Bludo.txt");
	while (temp != NULL)
	{
		fout << temp->KategBludo << endl;
		fout << temp->NazvanieBludo << endl;
		fout << temp->VesBludoGr << endl;
		fout << temp->StoumostBludoRub << endl;

		temp = temp->Prev;
	}
	fout.close();
}

void DeleteList()
{
	while (Head)
	{
		Tail = Head->Prev;
		delete Head;
		Head = Tail;
	}
}

void Pop()
{
	if (Head != NULL)
	{
		Tail = Head;
		Head = Head->Prev;
		delete Tail;
	}
	else 
	cout << "Стек Пуст." << endl;
}

void Memmory()
{
	Bludo* LocalHead = Head;
	int Size = 0;
	while (LocalHead)
	{
		Size += sizeof(LocalHead->KategBludo);
		Size += sizeof(LocalHead->NazvanieBludo);
		Size += sizeof(LocalHead->VesBludoGr);
		Size += sizeof(LocalHead->StoumostBludoRub);
		
		LocalHead = LocalHead->Prev;
	}
	cout << "Размер Стека = " << Size << " байт." << endl;
}

int main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	int Key;
	do
	{
		cout << "1 - Добавить элемент стека в ручном режиме." << endl;
		cout << "2 - Вывести все элементы стека." << endl;
		cout << "3 - Записать стек в файл." << endl;
		cout << "4 - Заполнить стек из файла." << endl;
		cout << "5 - Удалить последний добавленный элемент стека." << endl;
		cout << "6 - Вывести размер стека." << endl;
		cin >> Key;
		switch (Key)
		{
		case 1:
		{
			Push();
			break;
		}
		case 2:
		{
			Print();
			break;
		}
		case 3:ListToFile();
			break;
		case 4:FromFileToList();
			break;
		case 5:Pop();
			break;
		case 6:
			Memmory();
			break;
		}
	} while (Key != 0);
	
	DeleteList();
	_getch();
	return 0;
}