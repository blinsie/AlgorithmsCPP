#include "Queue.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Queue::push(int data)
{
    List *tmp = new List;
    tmp -> x = data;
    tmp -> Next = NULL;
    if (Head == NULL) {
        Head = tmp;
        Current = tmp;
    }
    else {
        Current -> Next = tmp;
        Current = tmp;
    }
}
void Queue::print()
{
    if (Head != NULL) {
        List *tmp = new List;
        tmp = Head;
        while (tmp != NULL) {
            cout << tmp -> x << " ";
            tmp = tmp -> Next;
        }
        cout << endl; delete(tmp);
    }
    else cout << "There is no queue yet.\n";
}
void Queue::del()
{
    if (Head != NULL) {
        List *tmp = new List;
        tmp = Head;
        Head = Head -> Next;
        delete(tmp);
        tmp = NULL;
        delete tmp;
    }
    else cout << "There is no queue yet.\n";
}
