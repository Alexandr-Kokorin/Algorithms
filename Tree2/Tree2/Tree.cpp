#include <iostream>
#include "Tree.h"

Node* New(int num, char sign) {
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node->num = num;
	node->sign = sign;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int Prior(char sign) {
	if (sign == '+' || sign == '-') return 2;
	if (sign == '*' || sign == '/') return 3;
	if (sign >= '0' && sign <= '9') return 10;
}

Node* MakeTree(int first, int last, char* mass) {
	Node* Tree = New(0, '0');
	int MinPrior = 10, index;
	if (first == last) {
		Tree->num = atoi(&mass[first]);
		Tree->left = NULL;
		Tree->right = NULL;
		return Tree;
	}
	for (int i = first; i < last; i++) {
		if (Prior(mass[i]) <= MinPrior) {
			MinPrior = Prior(mass[i]);
			index = i;
		}
	}
	Tree->sign = mass[index];
	Tree->left = MakeTree(first, index - 1, mass);
	Tree->right = MakeTree(index + 1, last, mass);
	return Tree;
}

void Pre_order(Node* Tree) {
	if (Tree == NULL) return;
	if (Tree->num != 0) printf("%d ", Tree->num);
	if (Tree->sign != '0') printf("%c ", Tree->sign);
	Pre_order(Tree->left);
	Pre_order(Tree->right);
}

void In_order(Node* Tree) {
	if (Tree == NULL) return;
	In_order(Tree->left);
	if (Tree->num != 0) printf("%d ", Tree->num);
	if (Tree->sign != '0') printf("%c ", Tree->sign);
	In_order(Tree->right);
}

void Post_order(Node* Tree) {
	if (Tree == NULL) return;
	Post_order(Tree->left);
	Post_order(Tree->right);
	if (Tree->num != 0) printf("%d ", Tree->num);
	if (Tree->sign != '0') printf("%c ", Tree->sign);
}

int CalcTree(Node* Tree) {
	if (Tree->left == NULL) return Tree->num;
	int num1 = CalcTree(Tree->left);
	int num2 = CalcTree(Tree->right);
	switch (Tree->sign) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	}
}