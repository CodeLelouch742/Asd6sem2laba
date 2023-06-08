#include "heap.h"

int* my_dij_bin(int** graph, int count, int beginning)
{

	int* path = new int[count];
	BinaryHeap binHeap;
	for (int i = 0; i < count; i++)
	{
		path[i] = 999999999;
	}
	path[beginning] = 0;
	binHeap.push(path[beginning], beginning);
	while (!binHeap.empty())
	{
		pair<int, int> firstElement = binHeap.top();
		binHeap.pop();
		for (int i = 0; i < count; i++)
		{
			int temp = graph[firstElement.second][i];
			if (graph[firstElement.second][i] && path[firstElement.second] + graph[firstElement.second][i] < path[i])
			{
				{
					path[i] = path[firstElement.second] + graph[firstElement.second][i];
					binHeap.push(path[i], i);
				}
			}
		}
	}
	return path;
}

int* my_dij_fib(int** graph, int count, int beginning)
{
	int* path = new int[count];
	FibonacciHeap<int> fibonacciHeap;
	for (int i = 0; i < count; i++)
	{
		path[i] = 999999999;
	}
	path[beginning] = 0;
	fibonacciHeap.insert(path[beginning], beginning);
	while (!fibonacciHeap.isEmpty())
	{
		int value = fibonacciHeap.getMinimum_dij_node();
		fibonacciHeap.removeMinimum();
		for (int i = 0; i < count; i++)
		{
			if (graph[value][i] && path[value] + graph[value][i] < path[i])
			{
				{
					path[i] = path[value] + graph[value][i];
					fibonacciHeap.insert(path[i], i);
				}
			}
		}
	}
	return path;
}