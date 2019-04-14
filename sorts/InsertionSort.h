#pragma once


//Insertion sort - time complexity O(n^2) space complexity O(1), stable

template <typename T>
void insertionSort(T arr[], int size)
{
	int = j;
	T key;

	for (int i = 1; i < size; i++)
	{
		j = i - 1;
		key = arr[i];

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}