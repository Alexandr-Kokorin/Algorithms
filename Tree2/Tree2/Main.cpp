#include <iostream>
#include "Tree.h"

int main()
{
    Node* Tree = NULL;
    char Str[6] = "9-2*3";
    printf("Expression %s", Str);
    Tree = MakeTree(0, 4, Str);
    printf("\nPre_order  ");
    Pre_order(Tree);
    printf("\nIn_order   ");
    In_order(Tree);
    printf("\nPost_order ");
    Post_order(Tree);
    printf("\nResult = %d", CalcTree(Tree));
}