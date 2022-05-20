#include <iostream>
#include "Heap.h"

Heap* New() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->Size = 0;
	heap->Array = NULL;
	return heap;
}

void Add(Heap* heap, int info) {
	heap->Array = (int*)realloc(heap->Array, (heap->Size + 1) * sizeof(int));
	heap->Array[heap->Size] = info;
	int index = heap->Size;
	while (index > 0 && heap->Array[(index - 1) / 2] < heap->Array[index]) {
		int temp = heap->Array[(index - 1) / 2];
		heap->Array[(index - 1) / 2] = heap->Array[index];
		heap->Array[index] = temp;
		index = (index - 1) / 2;
	}
	heap->Size++;
}

int HeadExtraction(Heap* heap) {
	heap->Size--;
	int result = heap->Array[0];
	heap->Array[0] = heap->Array[heap->Size];
	heap->Array = (int*)realloc(heap->Array, heap->Size * sizeof(int));
	int index = 0;
	while (index * 2 + 1 < heap->Size && (heap->Array[index * 2 + 1] > heap->Array[index] || heap->Array[index * 2 + 2] > heap->Array[index])) {
		if (heap->Array[index * 2 + 1] > heap->Array[index * 2 + 2]) {
			int temp = heap->Array[index];
			heap->Array[index] = heap->Array[index * 2 + 1];
			heap->Array[index * 2 + 1] = temp;
			index = index * 2 + 1;
		}
		else {
			int temp = heap->Array[index];
			heap->Array[index] = heap->Array[index * 2 + 2];
			heap->Array[index * 2 + 2] = temp;
			index = index * 2 + 2;
		}
	}
	return result;
}

void Print(Heap* heap) {
	for (int i = 0; i < heap->Size; i++) {
		printf("%d ", heap->Array[i]);
	}
}