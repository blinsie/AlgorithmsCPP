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
        List *Head = NULL; ///  ��������� �� ������ �������
        List *Current = NULL; ///��������� �� ������� ������� �������
        void push(int); ///�������� ������� � �������
        void print();
        void del (); /// ������� ������� �� �������
};
#endif // QUEUE_H
