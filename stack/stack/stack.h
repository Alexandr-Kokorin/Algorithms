#pragma once
struct Stack
{
	char data[20][16];
	int top;
};

void init(Stack* stack);

bool is_empy(Stack* stack);

bool is_full(Stack* stack);

int size(Stack* stack);

void push(Stack* stack, char* str);

void pop(Stack* stack);

char* peek(Stack* stack);

