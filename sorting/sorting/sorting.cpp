#include "custom.h"
#include <iostream>

/* Helpers */
template <typename T>
int partition(T *arr, int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

template <typename T>
int partition_r(T *arr, int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[low]);

	return partition(arr, low, high);
}

template <typename T>
void merge(T *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	T *L = new T[n1], *R = new T[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l+i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m+1+j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

template <typename T>
void heapify(T *arr, int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}


/* Slow sortings */
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

/* Faster sortings */
template <typename T>
void quicksort(T arr, int l, int r)
{
	int i, j;
	i = l;
	j = r;
	int middle = arr[(i + j) / 2];

	do
	{
		while (middle > arr[i])
			i++;
		while (middle < arr[j])
			j--;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (i < r)
		quicksort(arr, i, r);
	if (j > l)
		quicksort(arr, l, j);
}

template <typename T>
void rpquicksort(T *arr, int low, int high)
{
	if (low < high) {

		int pi = partition_r(arr, low, high);

		rpquicksort(arr, low, pi);
		rpquicksort(arr, pi + 1, high);
	}
}

template <typename T>
void lpquicksort(T *arr, int low, int high)
{
	if (low < high) {

		int pi = partition(arr, low, high);

		lpquicksort(arr, low, pi);
		lpquicksort(arr, pi + 1, high);
	}
}

template <typename T>
void mergesort(T *arr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) >> 1;

		mergesort(arr, l, m);
		mergesort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

template <typename T>
void heapsort(T *arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

int main()
{
	int N = 0;
	std::cout << "> ";
	std::cin >> N;

	int *data = getradomarray(N);

	std::cout << mtime(heapsort, data, N) << "s";

	printarr(data, N);

	std::cin.sync();
	std::cin.get();
	return 0;
}