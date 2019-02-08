#include "custom.h"
#include <iostream>

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


template <typename T>
void insertionbinarysort(T* arr, int l) 
{ 
	int i, loc, j, k;
	T select;
  
  for (i = 1; i < l; ++i) 
  { 
    j = i - 1;
    select = arr[i]; 
  
		loc = binarysearch(arr, select, 0, j); 
  
    while (j >= loc) 
    { 
			arr[j+1] = arr[j];
      j--; 
    } 
		arr[j+1] = select;
  } 
} 

int main()
{
	int N = 0;
	
	std::cin >> N;

	int *data = getradomarray(N);

	std::cout << mtime(insertionbinarysort, data, N) << "s";

	//printarr(data, N);


	std::cin.sync();
	std::cin.get();
	return 0;
}