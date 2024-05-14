#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxheapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
        largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		maxheapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		maxheapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		maxheapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 2,1,0,5,2,9,5,1};
	int n = 8;

	heapSort(arr, n);
	printf("Sorted array is\n");
	printArray(arr, n);
}