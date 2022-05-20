#include <iostream>
#include <stdio.h>
#include <locale.h>
#include "stack.h"

int Prior(char a) {
	if (a == '(') return 0;
	if (a == ')') return 1;
	if (a == '+' || a == '-') return 2;
	if (a == '*' || a == '/') return 3;
}

float strToNum(char* str) {
	float result = 0;
	int i = 0;
	if (str[0] == '-') i = 1;
	while (str[i] != ',' && str[i] != '\0') {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	float x = 10;
	if (str[i] == ',') i++;
	while (str[i] != '\0') {
		result += (str[i] - '0') / x;
		x *= 10; i++;
	}
	if (str[0] == '-') result *= -1;
	return result;
}

char sNum[16] = "\0";
char* numToStr(float num) {
	sprintf_s(sNum, "%f", num);
	int i = 0;
	while (sNum[i] != ',') {
		i++;
	}
	i += 6;
	while (sNum[i] == '0') {
		i--;
	}
	if (sNum[i] == ',') sNum[i] = '\0';
	else sNum[i+1] = '\0';
	return sNum;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Stack *stack;
	stack = (Stack*)malloc(sizeof(Stack));
    init(stack);
    char str[128];
	printf("Введите выражение: ");
	gets_s(str);
	
	int i = 0;
	char temp[] = "(";
	while (str[i] != '\0') {
		if (str[i] == '(') push(stack, temp);
		if (str[i] == ')' && !is_empy(stack)) pop(stack);
		else if (str[i] == ')' && is_empy(stack)) { printf("Выражение некорректно\n"); exit(0); }
		i++;
	}
	if (is_empy(stack)) printf("Выражение корректно\n");
	else { printf("Выражение некорректно\n"); exit(0); }

	char post[128] = "\0";
	i = 0;
	int j = 0;
	while (str[i] != '\0') {
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',') {
			post[j] = str[i]; j++;
			if ((str[i + 1] <= '0' || str[i + 1] >= '9') && str[i+1] != ',') {
				post[j] = ' '; j++;
			}
		}
		if (str[i] == '(') { temp[0] = str[i]; push(stack, temp); }
		if (str[i] == ')') {
			while (peek(stack)[0] != '(') {
				post[j] = peek(stack)[0]; j++;
				post[j] = ' '; j++;
				pop(stack);
			}
			pop(stack);
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (is_empy(stack)) { temp[0] = str[i]; push(stack, temp); }
			else {
				if (Prior(str[i]) > Prior(peek(stack)[0])) { temp[0] = str[i]; push(stack, temp); }
				else {
					while (Prior(peek(stack)[0]) >= Prior(str[i])) {
						post[j] = peek(stack)[0]; j++;
						post[j] = ' '; j++;
						pop(stack);
					}
					temp[0] = str[i]; push(stack, temp);
				}
			}
		}
		i++;
	}
	while (!is_empy(stack)) {
		post[j] = peek(stack)[0]; j++;
		post[j] = ' '; j++;
		pop(stack);
	}
	printf("Результат в постфиксной записи: %s\n", post);

	char number[16] = "\0";
	i = 0;
	j = 0;
	while (post[i] != '\0') {
		if ((post[i] >= '0' && post[i] <= '9') || post[i] == ',') {
			number[j] = post[i]; j++; 
			number[j] = '\0';
			if (post[i + 1] == ' ') { 
				push(stack, number); j = 0; 
			}
		}
		if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/') {
			float num1 = strToNum(peek(stack));
			pop(stack);
			float num2 = strToNum(peek(stack));
			pop(stack);
			if (post[i] == '+') {
				push(stack, numToStr(num2 + num1));
			}
			if (post[i] == '-') {
				push(stack, numToStr(num2 - num1));
			}
			if (post[i] == '*') {
				push(stack, numToStr(num2 * num1));
			}
			if (post[i] == '/') {
				push(stack, numToStr(num2 / num1));
			}
		}
		i++;
	}
	printf("Результат вычисления выражения в постфиксной нотации: %s\n", peek(stack));
}