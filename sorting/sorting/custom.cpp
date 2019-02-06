#include "custom.h"

#include <random>
#include <ctime>
#include <iostream>


int* getradomarray(int x)
{
	srand(time(nullptr));
	int *a = new int[x];

	for (int i = 0; i < x; i++)
	{
		a[i] = 0 + rand() % 500;
	}

	return a;
}

float mtime(void(*f)(int*, int), int *arr, int l)
{
	int init = clock();
	(*f)(arr, l);

	return ((float)(clock() - init) / CLOCKS_PER_SEC);
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printarr(int *arr, int l)
{
	for (int i = 0; i < l; i++)
	{
		std::cout << arr[i] << " ";
	}
}