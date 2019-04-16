#include "Stack.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Stack::push(int data)
{
    List *tmp = new List;
    tmp -> x = data;
    tmp -> Next = Head;
    Head = tmp;
}
void Stack::print()
{
    if (Head != NULL) {
        List *tmp = new List;
        tmp = Head;
        while (tmp != NULL) {
            cout << tmp -> x << " ";
            tmp = tmp -> Next;
        }
        cout << endl; delete (tmp);
    }
    else cout << "There is no stack yet.\n";
}
void Stack::del()
{
    if (Head != NULL) {
        List *tmp = new List;
        tmp = Head;
        Head = Head -> Next;
        delete(tmp);
        tmp = NULL;
        delete tmp;
    }
    else cout << "There is no stack yet.\n";
}
