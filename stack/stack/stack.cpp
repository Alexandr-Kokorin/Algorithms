#include <iostream>
#include <stdio.h>
#include "stack.h"

void init(Stack* stack) {
	for (int i = 0; i < 20; i++) {
		stack->data[i][0] = '\0';
	}
	stack->top = -1;
}

bool is_empy(Stack* stack) {
	return stack->top < 0;
}

bool is_full(Stack* stack) {
	return stack->top >= 20;
}

int size(Stack* stack) {
	return stack->top + 1;
}

void push(Stack* stack, char* str) {
	if (!is_full(stack)) {
		stack->top += 1;
		int i = 0;
		while (str[i] != '\0') {
			stack->data[stack->top][i] = str[i];
			i++;
		}
		stack->data[stack->top][i] = '\0';
	}
	else { printf("Стек переполнен\n"); exit(0); }
}

void pop(Stack* stack) {
	if (!is_empy(stack)) {
		stack->data[stack->top][0] = '\0';
		stack->top -= 1;
	}
	else { printf("Стек пуст\n"); exit(0); }
}

char* peek(Stack* stack) {
	return stack->data[stack->top];
}