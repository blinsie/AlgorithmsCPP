#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap()
{
    h = new int[SIZE];
    HeapSize = 0;
}

void Heap::add(int elem)
{
    int i, parent;
    i = HeapSize;
    h[i] = elem; ///добавление в конец массива
    parent = (i-1)/2; ///индекс родителя

    while (h[i] > h[parent])
    {
        if(h[i] > h[parent])
            swap(h[i], h[parent]);
        i = parent;
        parent = (i-1)/2;
    }
    HeapSize++;
}

void Heap::print()
{
    for (int i = 0; i < HeapSize; i++)
        cout << h[i] << " -- ";
    cout << endl;
}

void Heap::heapify(int i)
{
    int left, right, temp;
    left = 2*i + 1;
    right = 2*i + 2;

    if ((left <= HeapSize) && (h[i] < h[left])) {
        swap(h[i], h[left]);
        heapify(left);
    }
    if ((right <= HeapSize) && (h[i] < h[right])) {
        swap(h[i], h[right]);
        heapify(right);
    }
}

void Heap::delmax()
{
    h[0] = h[HeapSize-1];
    HeapSize--;
    heapify(0);
    cout << "End of deleting.\n";
}
