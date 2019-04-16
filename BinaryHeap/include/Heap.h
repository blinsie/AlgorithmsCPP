#ifndef HEAP_H
#define HEAP_H
#define SIZE 10

class Heap
{
    private:
        int *h;  ///указатель на начало кучи
        int HeapSize; ///размер кучи
    public:
        Heap();
        void add(int);
        void print();
        void delmax();
        void heapify(int); /// пирамидальный порядоk
};

#endif // HEAP_H
