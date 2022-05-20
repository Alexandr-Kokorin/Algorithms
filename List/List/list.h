struct List
{
	int info;
	List* next;
};

List* New();

int Size(List* list);

List* Add(List* list, int index, int info);

List* Delete(List* list, int info);

void Print(List* list);
