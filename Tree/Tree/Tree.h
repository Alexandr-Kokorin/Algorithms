struct Node {
	int info;
	Node* left;
	Node* right;
};

Node* New(int info);
Node* Add(Node* node, int info);
void Print(Node* node);
int Number_sheets(Node* node);
int Height(Node* node);
void Pre_order(Node* node);
void In_order(Node* node);
void Post_order(Node* node);
void DelTree(Node** node);

