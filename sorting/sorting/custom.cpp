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
	time_t init = clock();
	(*f)(arr, l);
	float finish = ((float)(clock() - init) / CLOCKS_PER_SEC);
	
	printf("\a");

	return finish;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printarr(int *arr, int l)
{
	std::cout << std::endl;
	for (int i = 0; i < l; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int binarysearch(int *arr, int item, int low, int high)
{
	if (high <= low)
		return (item > arr[low]) ? (low + 1) : low;

	int mid = (low + high)/2;

	if (item == arr[mid])
		return mid+1;

	if (item > arr[mid])
		return binarysearch(arr, item, mid+1, high);
	return binarysearch(arr, item, low, mid-1);
}