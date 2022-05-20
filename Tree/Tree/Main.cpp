#include <iostream>
#include "Tree.h"

int main()
{
    Node* Tree = NULL;
    int mass[5] = { 5,1,2,9,8 };
    for (int i = 0; i < 5; i++)
        Tree = Add(Tree, mass[i]);
    Print(Tree);
    printf("\ncount = %d , height = %d\n", Number_sheets(Tree), Height(Tree));
    printf("\nPre_order  ");
    Pre_order(Tree);
    printf("\nIn_order   ");
    In_order(Tree);
    printf("\nPost_order ");
    Post_order(Tree);
    DelTree(&Tree);
    getchar();
}
