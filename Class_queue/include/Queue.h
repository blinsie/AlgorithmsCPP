#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstddef> /// for null pointer

class Queue
{
    public:
        struct List {
            int x;
            List *Next; };
        List *Head = NULL; ///  указатель на начало очереди
        List *Current = NULL; ///указатель на текущий элемент очереди
        void push(int); ///вставить элемент в очередь
        void print();
        void del (); /// удалить элемент из очереди
};
#endif // QUEUE_H
