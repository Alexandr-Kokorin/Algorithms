#include <iostream>
#include "list.h"

List* New() {
	List* list;
	list = (List*)malloc(sizeof(List));
	list->info = 0;
	list->next = NULL;
	return list;
}

int Size(List* list) {
	int count = 0;
	List* temp = list;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

List* Add(List* list, int index, int info) {
	List* part = New();
	part->info = info;
	if (index <= 0) {
		part->next = list;
		return part;
	}
	int count = 0;
	List* temp1 = list;
	while (count != index - 1 && temp1->next != NULL) {
		temp1 = temp1->next;
		count++;
	}
	List* temp2 = temp1;
	temp1 = temp1->next;
	temp2->next = part;
	part->next = temp1;
	return list;
}

List* Delete(List* list, int info) {
	int index = 0;
	List* temp = list;
	while (temp != NULL && temp->info != info) {
		temp = temp->next;
		index++;
	}
	if (temp == NULL) return list;
	if (index == 0) return list->next;
	int count = 0;
	temp = list;
	while (count != index - 1) {
		temp = temp->next;
		count++;
	}
	temp->next = temp->next->next;
	return list;
}

void Print(List* list) {
	List* temp = list;
	while (temp != NULL) {
		printf("%d ", temp->info);
		temp = temp->next;
	}
	printf("\n");
}