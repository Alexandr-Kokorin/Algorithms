#include <iostream>
#include "Tree.h"

Node* New(int info) {
	Node* node;
	node = (Node*)malloc(sizeof Node);
	node->info = info;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* Add(Node* node, int info) {
	if (node == NULL) return New(info);
	if (info > node->info) node->right = Add(node->right, info);
	else node->left = Add(node->left, info);
	return node;
}

void Print(Node* node) {
	static int n = 0;
	if (node == NULL) return;
	n++;
	Print(node->right);
	printf("(Level %d) %d\n", n, node->info);
	Print(node->left);
	n--;
}

int Number_sheets(Node* node) {
	static int n = 0;
	if (node == NULL) return 0;
	if (node->left == NULL && node->right == NULL) n++;
	Number_sheets(node->right);
	Number_sheets(node->left);
	return n;
}

int Height(Node* node) {
	static int n = 0, max = 0;
	if (node == NULL) return 0;
	n++;
	if (n > max) max = n;
	Height(node->right);
	Height(node->left);
	n--;
	return max-1;
}

void Pre_order(Node* node) {
	if (node == NULL) return;
	printf("%d ", node->info);
	Pre_order(node->left);
	Pre_order(node->right);
}

void In_order(Node* node) {
	if (node == NULL) return;
	In_order(node->left);
	printf("%d ", node->info);
	In_order(node->right);
}

void Post_order(Node* node) {
	if (node == NULL) return;
	Post_order(node->left);
	Post_order(node->right);
	printf("%d ", node->info);
}

void DelTree(Node** v) {
	if (*v) {
		DelTree(&((*v)->left));
		DelTree(&((*v)->right));
		free(*v);
	}
}
