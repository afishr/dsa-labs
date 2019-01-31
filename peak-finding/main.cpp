#include <iostream>
#include <ctime>

void mtime( int (*f)(int[], int, int), int data[], int start, int end )
{
	int init = clock();
	int	result = (*f)(data, start, end);

	std::cout << result << " " << data[result] << std::endl;
	std::cout << ((float)(clock() - init)/CLOCKS_PER_SEC) * 1000 << "ms" << std::endl;

}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
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

int main()
{
	int data[] = {1, 21, 324, 23 ,223, 12, 12, 3, 12, 3, 12, 3, 12, 3, 1231 ,23};

	int len = sizeof(data) / sizeof(int);

	mtime(findpeak1D, data, 0, len);

	return 0;
}