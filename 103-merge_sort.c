#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int left, int mid, int right);
void merge_sort_recursive(int arr[], int temp[], int left, int right);
void merge_sort(int arr[], size_t size);

/**
 * merge - Merge two sorted subarrays into one sorted subarray.
 * @arr: The array of integers to sort.
 * @temp: A temporary array to store the sorted subarray.
 * @left: The left index of the first subarray.
 * @mid: The right index of the first subarray and the left index of the second subarray.
 * @right: The right index of the second subarray.
 */
void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;     // index for the left subarray
    int j = mid + 1;  // index for the right subarray
    int k = left;     // index for the temp array

    // Merge the subarrays into temp in sorted order
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements from the left subarray into temp
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements from the right subarray into temp
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray from temp back into arr
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

/**
 * merge_sort_recursive - Sort an array of integers in ascending order using the merge sort algorithm through recursion.
 * @arr: The array of integers to sort.
 * @temp
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
