#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstddef> /// for null pointer

class Stack
{
    public:
        struct List {
            int x;
            List *Next; };
        List *Head = NULL; ///  указатель на начало стека
        void push(int); ///вставить элемент в стек
        void print();
        void del (); /// удалить элемент из стекa
};

#endif // STACK_H
