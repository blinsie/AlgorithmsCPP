#ifndef HEAP_H
#define HEAP_H
#define SIZE 10

class Heap
{
    private:
        int *h;  ///��������� �� ������ ����
        int HeapSize; ///������ ����
    public:
        Heap();
        void add(int);
        void print();
        void delmax();
        void heapify(int); /// ������������� ������k
};

#endif // HEAP_H
