struct Heap
{
	int Size;
	int* Array;
};

Heap* New();
void Add(Heap* heap, int info);
int HeadExtraction(Heap* heap);
void Print(Heap* heap);