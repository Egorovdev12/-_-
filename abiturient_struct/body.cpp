#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct person
{
	char lastname[30];
	char name[30];
	char otch[30];
	int gr;
	int EGE;
};

void surnamefind(int count, person list[])
{
	string find; int amount = 0; int s = 0; char chk; int *number = new int[20]; int a, b;
	cout << "Введите фамилию для поиска: " << endl; cin >> find;
	for (int j = 0; j < count; j++)
	{
		if ((string)list[j].lastname == find)
		{
			amount = amount + 1;
		}
	}
	cout << "Всего найдено " << amount << " людей по фамилии " << find << endl;
	if (amount != 0)
	{
		for (int j = 0; j < count; j++)
		{
			if ((string)list[j].lastname == find)
			{
				number[s] = j + 1; s = s + 1;
				cout << s << ". " << list[j].lastname << " " << list[j].name << " " << list[j].otch << " ";
				cout << list[j].gr << " г.р. " << "Сумма баллов " << list[j].EGE << "." << endl;
				cout << "Номер в списке: " << (j + 1) << "." << endl;
			}
		}
		cout << "Хотите внести корректировки?(y/n)" << endl;
		cin >> chk;
		if (chk == 'y')
		{
			if (s == 1)
			{
				a = number[0];
				cout << "Введите данные абитуриента " << endl;
				cout << "Фамилия: ";
				cin >> list[a - 1].lastname;
				cout << "Имя: ";
				cin >> list[a - 1].name;
				cout << "Отчество: ";
				cin >> list[a - 1].otch;
				cout << "Год рождения: ";
				cin >> list[a - 1].gr;
				cout << "Баллы ЕГЭ: ";
				cin >> list[a - 1].EGE;
			}
			else if (s > 1)
			{
				point:
				cout << "Чьи данные изменить? (Цифра перед именем)" << endl;
				cin >> a;
				if ((a > amount) || (a <= 0))
				{
					cout << "Ошибка! Неверно выбраны значения!" << endl;
					goto point;
				}
				else if ((a <= amount) && (a > 0))
				{
					b = number[a - 1];
					cout << "Введите данные абитуриента " << endl;
					cout << "Фамилия: ";
					cin >> list[b - 1].lastname;
					cout << "Имя: ";
					cin >> list[b - 1].name;
					cout << "Отчество: ";
					cin >> list[b - 1].otch;
					cout << "Год рождения: ";
					cin >> list[b - 1].gr;
					cout << "Баллы ЕГЭ: ";
					cin >> list[b - 1].EGE;
				}
			}
		}
		else if (chk == 'n')
		{
			return;
		}
		else
		{
			cout << "Ошибка ввода!" << endl; return;
		}
	}
	delete number;
}

long long check()
{
	long long size;
	fstream file("people.txt");
	file.seekg(0, ios::end);
	size = file.tellg();
	file.close();
	return size;
}

void sort(int count, person list[])
{
	person *points = new person[1];
	cout << "Отсортируем абитуриентов" << endl;
	int jey = 1;
	while (jey != 0)
	{
		jey = 0;
		for (int i = 0; i < (count - 1); i++)
		{
			if (list[i].EGE < list[i + 1].EGE)
			{
				points[0] = list[i + 1];
				list[i + 1] = list[i];
				list[i] = points[0];
				jey += 1;
			}
		}
	}
	cout << "Список для зачисления:" << endl;
	int v = 1;
	for (int i = 0; i < count; i++)
	{
		cout << v << ". " << list[i].lastname << " " << list[i].name << " " << list[i].otch << " " << list[i].EGE << endl;
		v = v + 1;
	}
	delete points;
}

int schitivanie(int count2, person list[])
{
	ifstream file("people.txt");
	while (!file.eof())
	{
		int i = count2;
		file >> list[i].lastname;
		file >> list[i].name;
		file >> list[i].otch;
		file >> list[i].gr;
		file >> list[i].EGE;
		count2 += 1;
	}
	file.close();
	ofstream rewrite("people.txt");
	rewrite.write("", 0);
	rewrite.close();
	cout << "Данные из файла успешно сохранены" << endl;
	return count2;
}

int vvod(int count1, person list[])
{
	char ao; int i = count1;
	cout << "Введите данные абитуриента " << endl;
	cout << "Фамилия: ";
	cin >> list[i].lastname;
	cout << "Имя: ";
	cin >> list[i].name;
	cout << "Отчество: ";
	cin >> list[i].otch;
	cout << "Год рождения: ";
	cin >> list[i].gr;
	cout << "Баллы ЕГЭ: ";
	cin >> list[i].EGE;
	count1 = count1 + 1;
	cout << "Данные сохранены. Ещё одного?(y/n)"; cin >> ao;
	if (ao == 'y')
		vvod(count1, list);
	else if (ao == 'n')
		return count1;
	else
	{
		cout << "Ошибка ввода!" << endl;
		return count1;
	}
}

void surname_sort(int count, person list[])
{
	person *helper = new person; int jey1 = 1;
	while (jey1 != 0)
	{
		jey1 = 0;
		for (int i = 0; i < (count - 1); i++)
		{
			if (list[i].lastname[0] > list[i + 1].lastname[0])
			{
				*helper = list[i + 1];
				list[i + 1] = list[i];
				list[i] = *helper;
				jey1 = jey1 + 1;
			}
		}
	}
	jey1 = 1;
	while (jey1 != 0)
	{
		jey1 = 0;
		for (int i = 0; i < (count - 1); i++)
		{
			if ((list[i].lastname[1] > list[i + 1].lastname[1]) && (list[i].lastname[0] == list[i + 1].lastname[0]))
			{
				*helper = list[i + 1];
				list[i + 1] = list[i];
				list[i] = *helper;
				jey1 = jey1 + 1;
			}
		}
	}
	int v = 1;
	for (int e = 0; e < count; e++)
	{
		cout << v << ". " << list[e].lastname << " " << list[e].name << " " << list[e].otch << " " << list[e].EGE << endl;
		v = v + 1;
	}
	delete helper;
}

void save(int count, person list[])
{
	int s = 1;
	ofstream fout("spisok.txt", ios_base::out | ios_base::trunc);
	for (int i = 0; i < count; i++)
	{
		fout << s << ". " << list[i].lastname << " " << list[i].name << " " << list[i].otch << " ";
		fout << list[i].gr << " г.р. " << "Сумма баллов " << list[i].EGE << "." << endl;
		s = s + 1;
	}
	cout << "Данные успешно переписаны." << endl;
}

void choose(int count, person list[])
{
	char ch1; long long emp; 
	cout << "Выберите: " << endl; cout << "1) Ввести данные вручную" << endl << "2) Считать из файла" << endl;
	cout << "3) Составить список по убыванию баллов" << endl << "Дополнительно:" << endl << "4) Посик по фамилии" << endl;
	cout << "5) Сортировка по фамилии" << endl; cout << "6) Сохранить в Spisok.txt" << endl;
	cin >> ch1; label:
	switch (ch1)
	{
	case '1': count = vvod(count, list); choose(count, list);
	case '2': emp = check();
		if (emp == 0)
		{
			cout << "Файл пуст." << endl;
			choose(count, list);
		}
		else
		{
			count = schitivanie(count, list); choose(count, list);
		}
	case '3': sort(count, list); choose(count, list);
	case '4': surnamefind(count, list); choose(count, list);
	case '5': surname_sort(count, list); choose(count, list);
	case '6': save(count, list); choose(count, list);
	case 'q': exit(0); 
	default: cout << "Ошибка ввода!" << endl; choose(count, list);
	}
}

int main()
{
	setlocale(0, "");
	cout << "                    Прогрмма для работы приемной комиссии" << endl;
	cout << endl << endl << "Выполняет операции необходимые любому университету при наборе первокурсников. ";
	cout << "Ведет учет абитуриентов, дополняя список каждый раз, как записываются новые. Максимальное кол-во абитуриентов";
	cout << " 300, но можно легко изменить и на 3000 и на 10000. Считывает имена из файла people.txt. Файл очищается после";
	cout << " считывания и закрывается, что означает что мы можем записать туда новые имена сразу после считывания. ";
	cout << "Правильно записывать новых абитуриентов в файл в следующем порядке:" << endl;
	cout << "Фамилия - Имя - Отчество - год рождения - сумма баллов. Обязательно через пробелили Enter. Ввод осуществляется";
	cout << " только латинскими буквами. Для выхода введите q вглавном меню." << endl << endl;
	person list[300]; int count = 0;
	choose(count, list);
}