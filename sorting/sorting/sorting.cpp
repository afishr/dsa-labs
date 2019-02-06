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
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
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



int main()
{
	int N = 0;
	
	std::cin >> N;

	int *data = getradomarray(N);

	bubblesort(data, N);

	for (int i = 0; i < N; i++)
	{
		std::cout << data[i] << " ";
	}
	

	std::cin.sync();
	std::cin.get();
	return 0;
}