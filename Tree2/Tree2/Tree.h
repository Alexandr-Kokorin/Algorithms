struct Node {
	int num;
	char sign;
	Node* left;
	Node* right;
};

Node* New(int num, char sign);
int Prior(char sign);
Node* MakeTree(int first, int last, char* mass);
void Pre_order(Node* Tree);
void In_order(Node* Tree);
void Post_order(Node* Tree);
int CalcTree(Node* Tree);