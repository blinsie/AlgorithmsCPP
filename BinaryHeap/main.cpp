#include <iostream>
#include "Heap.h"
#include <stdlib.h>
using namespace std;
int main()
{
    int menu, i, el;
    Heap heap;
    while (true) {
        cout << "1. Add Element.";
        cout << "\n2. Print Binary Heap.\n3. Delete maxElement.";
        cout << "\n0. Exit.\n==========================\nYour choice: ";
        cin >> menu; cout << endl;
        switch(menu)
        {
            case 1:
                {
                    cout << "Input element: ";
                    cin >> el; cout << endl; heap.add(el);
                    cout << "Successfully.\n"; break;
                }
            case 2:
                {
                    cout << "Binary Heap: ";
                    heap.print(); break;
                }
            case 3:
                {
                    heap.delmax(); break;
                }
            case 0: exit(0);
            default: "There is no match for this value. Try again.";
        }
    }
    return 0;
}
