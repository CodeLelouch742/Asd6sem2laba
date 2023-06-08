#include "heap.h"
#include "Dijkstra.h"

using namespace std;


int main()
{
	setlocale(0, "");
	int begin = 0, count = 0;
	cout << "Введите количество вершин: ";
	cin >> count;
	int** graph = new int* [count];

	for (int i = 0; i < count; i++)
	{
		graph[i] = new int[count];
	}

	cout << "Введите вершину из которой хотите найти путь: ";
	cin >> begin;
	cout << "Введите длины путей между вершинами." << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Из вершины -  " << i + 1 << endl;
		for (int j = 0; j < count; j++)
		{
			cout << "В вершину " << j + 1 << ": ";
			cin >> graph[i][j];
			cout << endl;
		}
		cout << endl;
	}

	//Двоичная куча
	auto st = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, micro> time = end - st;
	double endTime = 0;
	int numberTry = 100;

	cout << "Двоичная куча: " << endl;
	int* path = new int[count];
	for (int i = 0; i < numberTry; i++)
	{
		st = chrono::high_resolution_clock::now();
		my_dij_bin(graph, count, begin - 1);
		end = chrono::high_resolution_clock::now();
		time = end - st;
		endTime += time.count();
	}

	cout << "Время для двоичной кучи: " << endTime/numberTry << endl;
	path = my_dij_bin(graph, count, begin - 1);
	for (int i = 0; i < count; i++) if (path[i] != 999999999)
		cout << begin << " > " << i + 1 << " = " << path[i] << endl;
	else cout << begin << " > " << i + 1 << " = " << "маршрут недоступен" << endl;


	cout << endl << "*****************************************************************" << endl;

	endTime = 0;

	//Фибоначчиева куча
	cout << endl << "Фибоначчиева куча: " << endl;
	for (int i = 0; i < numberTry; i++)
	{
		st = chrono::high_resolution_clock::now();
		my_dij_fib(graph, count, begin - 1);
		end = chrono::high_resolution_clock::now();
		time = end - st;
		endTime += time.count();
	}

	cout << "Время для фибоначчиевой кучи: " << endTime / numberTry << endl;
	path = my_dij_fib(graph, count, begin - 1);
	for (int i = 0; i < count; i++) if (path[i] != 999999999)
		cout << begin << " > " << i + 1 << " = " << path[i] << endl;
	else cout << begin << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
	system("pause");
}