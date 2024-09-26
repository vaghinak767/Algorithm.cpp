#include <iostream>

int min(int x, int y) 
{
	return (x <= y) ? x : y; 
}

int fibSearch(int* arr, int n, int x)
{
	int f1 = 0;
	int f2 = 1;
	int f = 1;
	while (f < n)
	{
		f1 = f2;
		f2 = f;
		f = f1 + f2;
	}
	int offset = -1;
	while (f > 1)
	{
		int i = min(offset + f1, n - 1);
		if (arr[i] < x)
		{
			f = f2;
			f2 = f1;
			f1 = f - f2;
			offset = i;
		}
		else if (arr[i] > x)
			{
				f = f1;
				f2 = f2 - f1;
				f1 = f - f2;
			}
			else
			{
				return i;
			}
	}
	if (f2 && arr[offset + 1] == x)
	{
		return offset + 1;
	}
	return -1;
}

int main()
{
	int n = 0;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	std::cout << fibSearch(arr, n, 7);
	delete[]arr;
}

