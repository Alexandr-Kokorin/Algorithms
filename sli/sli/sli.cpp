#include <iostream>
#include <locale.h>

void sort(int* arr, int begin, int end) {
	if (end - begin < 1) return;
	sort(arr, begin, (begin + end) / 2);
	sort(arr, (begin + end) / 2 + 1, end);
	int i = begin;
	int j = (begin + end) / 2 + 1;
	int* temp = (int*)malloc((end - begin + 1) * sizeof(int));
	for (int t = 0; t <= end - begin; t++) {
		if ((arr[i] < arr[j] && i <= (begin + end) / 2) || j > end) {
			temp[t] = arr[i];
			i++;
		}
		else {
			temp[t] = arr[j];
			j++;
		}
	}
	for (int t = 0; t <= end - begin; t++) {
		arr[begin + t] = temp[t];
	}
	free(temp);
	printf("\nsort: ");
	for (int t = begin; t <= end; t++) {
		printf("%d ", arr[t]);
	}
}

int main(void)
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int size;
	int* arr;

	printf("Введите размер массива: ");
	scanf_s("%d", &size);
	arr = (int*)malloc(size * sizeof(int));

	printf("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");

	sort(arr, 0, size - 1);

	printf("\n\nОтсортированный массив:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
}