#include <iostream>
#include <ctime>

const int MAX = 100;

void mtime( int (*f)(int[], int, int), int data[], int start, int end )
{
	int init = clock();
	int	res = (*f)(data, start, end);

	std::cout << data[res] << std::endl;

	std::cout << ((float)(clock() - init)/CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}


void mtime( int (*f)(int[][MAX], int, int), int arr[][MAX], int rows, int columns )
{
	int init = clock();
	int	res = (*f)(arr, rows, columns);

	std::cout << res << std::endl;

	std::cout << ((float)(clock() - init)/CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;
}

int findpeak1D(int arr[], int start, int end)
{
	if (end - start == 1)
	{
		if (start == 0)
			return start;
		else
			return end;
	}

	int i = (start + end) >> 1; // Faster division by 2

	if (arr[i] < arr[i-1])
		return findpeak1D(arr, start, i);

	else if (arr[i] < arr[i+1])
		return findpeak1D(arr, i, end);

	else
		return i;

}

int findMax(int arr[][MAX], int rows, int mid, int &max)
{
	int max_index = 0;
	for (int i = 0; i < rows; i++)
	{
		if (max < arr[i][mid])
		{
			max = arr[i][mid];
			max_index = i;
		}
	}
	return max_index;
}

int findPeakRec(int arr[][MAX], int rows, int columns, int mid)
{
	int max = 0;
	int max_index = findMax(arr, rows, mid, max);

	if (mid == 0 || mid == columns-1)
		return max;

	if (max >= arr[max_index][mid-1] && max >= arr[max_index][mid+1])
		return max;

	if (max < arr[max_index][mid-1])
		return findPeakRec(arr, rows, columns, mid - mid/2);

	return findPeakRec(arr, rows, columns, mid+mid/2);
}

int findpeak2D(int arr[][MAX], int rows, int columns)
{
	return findPeakRec(arr, rows, columns, columns/2);
}

int main()
{
	int size = 10;
	int rows = 4, columns = 4;

	int data[] = {1, 21, 324, 23, 223, 12, 12, 3, 12, 1231};

	int arr[][MAX] = {{ 10, 8, 10, 10 },
	                  { 14, 13, 12, 11 },
	                  { 15, 9, 22, 21 },
	                  { 16, 17, 19, 20 } };

	std::cout << "1D peak" << std::endl;
	mtime(findpeak1D, data, 0, size-1);
	std::cout << std::endl << "2D peak" << std::endl;
	mtime(findpeak2D, arr, rows, columns);

	return 0;
}