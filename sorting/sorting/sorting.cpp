#include "pch.h";
#include <iostream>
#include <random>
#include <time.h>

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

template <typename T>
float mtime(void(*f)(T*, int), T *arr, int l)
{
	int init = clock();
	(*f)(arr, l);
	
	return ((float)(clock() - init) / CLOCKS_PER_SEC);
}

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void printarr(T *arr, int l)
{
	for (int i = 0; i < l; i++)
	{
		std::cout << arr[i] << " ";
	}
}

/* Sortings */
template <typename T>
void bubblesort(T *arr, int l)
{
	bool flag;
	for (int i = 0; i < l; i++)
	{
		flag = false;
		for (int j = 0; j < l - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

template <typename T> 
void selectionSort(T * arr, int l) {
	int i, j, min_idx;
	for (i = 0; i < l - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < l; j++)
			if (arr[j] < arr[min_idx]) min_idx = j;
		swap(arr[min_idx], arr[i]);
	}
}

template <typename T>
void insertionsort(T *arr, int l)
{
	for (int i = 0; i < l; i++)
	{
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}


int main()
{
	int N = 0;
	
	std::cin >> N;

	int *data = getradomarray(N);

	std::cout << mtime(bubblesort, data, N) << "s";

	//printarr(data, N);

	std::cin.sync();
	std::cin.get();
	return 0;
}