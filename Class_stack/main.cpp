#include <iostream>
#include "Stack.h"
#include <stdlib.h>

using namespace std;

int main()
{
    int menu; int value;
    Stack *st = new Stack();

    while (true) {
        cout << "1. Add value to the stack.";
        cout << "\n2. Delete value from the stack.\n";
        cout << "3. Print stack.\n";
        cout << "0. Exit.\n";
        cout << "Make decision: "; cin >> menu; cout << endl;
        switch (menu) {
        case 1 : {
                    cout << "Input value:  "; cin >> value;
                    cout << endl;
                    st -> push(value);
                    break;
                 }

        case 2 : {
                    cout << "Deleting...\n";
                    st -> del();
                    break;
                 }
        case 3 : {
                    st->print();
                    break;
                 }
        case 0 : { exit(0); break; }

        default: cout << "The is no matching for this value. Try again.\n";
        } } return 0; }
