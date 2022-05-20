#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include "list.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    List* list = NULL;
    FILE* file;
    char str[256];
    file = fopen("list.txt", "r");
    fscanf(file, "%[^\n]\n", str);
    fclose(file);
    int i = 0, j = 0;
    char number[16] = "\0";
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            number[j] = str[i];
            j++;
            number[j] = '\0';
        }
        else {
            list = Add(list, Size(list), atoi(number));
            j = 0;
            number[j] = '\0';
        }
        i++;
    }
    list = Add(list, Size(list), atoi(number));
    int choice = 0;
    int index, info;
    while (choice != 5) {
        printf("--------------------\n");
        printf("Введите номер операции, которую хотите совершить:\n");
        printf("1. Добавить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Кол-во элементов в списке\n");
        printf("4. Вывести список\n");
        printf("5. Выход\n");
        printf("--------------------\n");
        printf("Операция номер: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Введите индекс: ");
            scanf_s("%d", &index);
            printf("Введите значение: ");
            scanf_s("%d", &info);
            list = Add(list, index, info);
            break;
        case 2:
            printf("Введите значение: ");
            scanf_s("%d", &info);
            list = Delete(list, info);
            break;
        case 3:
            printf("Кол-во элементов - %d\n", Size(list));
            break;
        case 4:
            printf("Список: ");
            Print(list);
            break;
        default:
            break;
        }
    }
}