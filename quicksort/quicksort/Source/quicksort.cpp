#include <stdio.h>

template <typename T>
void swap(T* a, T* b) {

	T t = *a;
	*a = *b;
	*b = t;

}

template <typename T>
T partition(T array[], int l, int r) {

	T pivot = array[r];
	T i = (l - 1);

	for (T j = l; j <= r - 1; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[r]);
	return (i + 1);

}

template <typename T>
void quicksort(T array[], int l, int r) {

	if (l < r) {
		T pivot = partition(array, l, r);
		quicksort(array, l, pivot - 1);
		quicksort(array, pivot + 1, r);
	}

}

int main() {

	int i;
	unsigned int array[10] = { 3, 6, 1, 7, 2, 0, 4, 5, 9, 8 };

	printf("array: ");
	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	quicksort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

	printf("sorted array: ");

	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;

}
