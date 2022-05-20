#include <iostream>
#include "Heap.h"

const int size = 9;

int* sort(int* array) {
	Heap* heap = New();
	printf("Make heap\n");
	for (int i = 0; i < size; i++) {
		Add(heap, array[i]);
		Print(heap);
		printf("HeapSize = %d\n", heap->Size);
	}
	printf("Heap\n");
	Print(heap);
	printf("HeapSize = %d\n", heap->Size);
	printf("Sort\n");
	int* temp = (int*)malloc(size * sizeof(int));
	for (int i = size - 1; i >= 0; i--) {
		temp[i] = HeadExtraction(heap);
		Print(heap);
		for (int j = i; j < size; j++) {
			printf("%d ", temp[j]);
		}
		printf("HeapSize = %d\n", heap->Size);
	}
	return temp;
}

bool isSort(int* array, int size) {
	bool flag = true;
	bool inc = true;
	int i = 0;
	while (array[i] == array[i + 1]) i++;
	if (array[i] > array[i + 1]) inc = false;
	for (i; i < size - 1; i++) {
		if (inc) {
			if (array[i] > array[i + 1]) flag = false;
		}
		else {
			if (array[i] < array[i + 1]) flag = false;
		}
	}
	return flag;
}

int main()
{
	int* array = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &array[i]);
	}
	printf("%d\n", isSort(array, size));
	array = sort(array);
	printf("%d\n", isSort(array, size));
}