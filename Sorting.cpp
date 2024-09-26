#include <iostream>
#include <cstdlib>
#include <vector>
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int max(int* arr, int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		bool flag = false;
		for (int j = n - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

void SelectionSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		swap(arr[min], arr[i]);
	}
}

void InsertionSort(int* arr, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void merge(int* arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < n2) {
		arr[k] = R[j];
		++j;
		++k;
	}

	delete[] L;
	delete[] R;
}

void mergeSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void MergeSort(int* arr, int n)
{
	mergeSort(arr, 0, n - 1);
}

void heapify(int* arr, int n, int i)
{
	int larg = i;
	int l = 2 * i + 2;
	int r = 2 * i + 1;
	if (l < n && arr[l] > arr[i])
	{
		larg = l;
	}
	if (r < n && arr[r] > arr[larg])
	{
		larg = r;
	}
	if (larg != i)
	{
		swap(arr[i], arr[larg]);
		heapify(arr, n, larg);
	}
}

void HeapSort(int* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		heapify(arr, n, i);
	}
	for (int i = n - 1; i > 0; --i)
	{
		swap(arr[i], arr[0]);
		heapify(arr, i, 0);
	}
}

int Hpartition_(int* arr, int l, int h)
{
	int i = l;
	int pivot = arr[h];
	for (int j = l; j < h; ++j)
	{
		if (arr[j] < pivot)
		{
			swap(arr[i], arr[j]);
			++i;
		}
	}
	swap(arr[i], arr[h]);
	return i;
}

int Lpartition_(int* arr, int l, int h)
{
	swap(arr[l], arr[h]);
	return Hpartition_(arr, l, h);
}

int Mpartition_(int* arr, int l, int h)
{
	swap(arr[l + (h - l) / 2], arr[h]);
	return Lpartition_(arr, l, h);
}

int Lpartition(int* arr, int l, int h)
{
	int pivot = arr[h];
	int i = l, j = h - 1;
	while (1)
	{
		while (arr[i] < pivot) {
			++i;
		}
		while (arr[j] > pivot)
		{
			--j;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
			++i;
			--j;
		}
		else
			break;
	}
	swap(arr[h], arr[i]);
	return i;
}

int Hpartition(int* arr, int l, int h)
{
	int pivot = arr[l];
	int i = l + 1, j = h;
	while (1)
	{
		while (arr[i] < pivot)
		{
			++i;
		}
		while (arr[j] > pivot)
		{
			--j;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
			++i;
			--j;
		}
		else
			break;
	}
	swap(arr[l], arr[j]);
	return j;
}

int Mpartition(int* arr, int l, int h)
{
	int pivot = arr[l + (h - l) / 2];
	int i = l;
	int j = h;
	while (i < j)
	{
		if (arr[j] == pivot)
			--j;
		while (arr[i] < pivot)
		{
			++i;
		}
		while (arr[j] > pivot)
		{
			--j;
		}
		if (i < j)
			swap(arr[i], arr[j]);
	}
	return i;
}

int Rpartition(int* arr, int l, int h)
{
	int i = l + (rand() % (h - l + 1));
	swap(arr[i], arr[h]);
	return Hpartition(arr, l, h);
}

void QuickSort(int* arr, int l, int h)
{
	if (l < h)
	{
		//int m = Lpartition_(arr, l, h);
		//int m = Lpartition(arr, l, h);
		//int m = Hpartition(arr, l, h);
		//int m = Hpartition_(arr, l, h);
		//int m = Mpartition(arr, l, h);
		//int m = Mpartition_(arr, l, h);
		int m = Rpartition(arr, l, h);
		QuickSort(arr, l, m - 1);
		QuickSort(arr, m + 1, h);
	}
}
//..................
//Linear
//..................

void CountingSort(int* arr, int n)
{
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	int rang = (max - min + 1);
	int* tmp = new int[rang]();

	for (int i = 0; i < n; ++i) {
		++tmp[arr[i] - min];
	}

	for (int i = 1; i < rang; ++i) {
		tmp[i] += tmp[i - 1];
	}

	int* out = new int[n];
	for (int i = n - 1; i >= 0; --i) {
		out[tmp[arr[i] - min] - 1] = arr[i];
		--tmp[arr[i] - min];
	}

	for (int i = 0; i < n; ++i) {
		arr[i] = out[i];
	}

	delete[] tmp;
	delete[] out;
}

void count_for_radix(int* arr, int n, int exp)
{
	int* out = new int[n];
	int count[10] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		++count[(arr[i] / exp) % 10];
	}
	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; --i)
	{
		out[count[(arr[i] / exp) % 10] - 1] = arr[i];
		--count[(arr[i] / exp) % 10];
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i] = out[i];
	}
	delete[] out;
}

void RadixSort(int* arr, int n)
{
	int m = max(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		count_for_radix(arr, n, exp);
	}
}

void insertionSort(std::vector<float>& bucket) {
	for (int i = 1; i < bucket.size(); ++i) {
		float key = bucket[i];
		int j = i - 1;
		while (j >= 0 && bucket[j] > key) {
			bucket[j + 1] = bucket[j];
			j--;
		}
		bucket[j + 1] = key;
	}
}

void BucketSort(float *arr, int n) {
	std::vector<float> *b = new std::vector<float>[n];

	for (int i = 0; i < n; i++) {
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		insertionSort(b[i]);
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < b[i].size(); j++) {
			arr[index++] = b[i][j];
		}
	}
}

int main()
{
	int n = 0;
	std::cin >> n;
	float* arr = new float[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}
	BucketSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
	delete[]arr;
}
