#include <iostream>
#include "Queue.h"
#include <stdlib.h>

using namespace std;

int main()
{
    int menu; int value;
    Queue *qu = new Queue();

    while (true) {
        cout << "1. Add value to the queue.";
        cout << "\n2. Delete value from the queue.\n";
        cout << "3. Print queue.\n"; cout << "0. Exit.\n";
        cout << "Make decision: "; cin >> menu; cout << endl;
        switch (menu) {
        case 1 : {
                    cout << "Input value:  "; cin >> value;
                    cout << endl;
                    qu -> push(value);
                    break;
                 }

        case 2 : {
                    cout << "Deleting...\n";
                    qu -> del();
                    break;
                 }
        case 3 : {
                    qu -> print();
                    break;
                 }
        case 0 : { exit(0); break; }

        default: cout << "The is no matching for this value. Try again.\n";
        } } return 0;
}
