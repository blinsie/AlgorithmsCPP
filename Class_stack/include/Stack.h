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
        List *Head = NULL; ///  ��������� �� ������ �����
        void push(int); ///�������� ������� � ����
        void print();
        void del (); /// ������� ������� �� ����a
};

#endif // STACK_H
