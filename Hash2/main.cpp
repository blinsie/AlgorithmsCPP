#include <iostream>
#include <stdlib.h>
#include <vector>
#define SIZE 100

using namespace std;

void init_vec(vector<string> &vec)
{
    for (int i = 0; i < vec.size(); i++)
      vec[i] = "-1";
}

int main()
{
    string surname; int value; int menu, i;
    vector<string> tab(SIZE); init_vec(tab);
    while (true)
    {
        cout << "1. Add Surname.";
        cout << "\n2. Print Hash-table.\n0. Exit.";
        cout << "\nYour choice: "; cin >> menu;
        cout << endl;
        switch(menu)
        {
            case 1:
                {
                    cout << "Input surname: ";
                    cin >> surname; cout << endl;
                    value = surname[0] % 100;   ///HASH-FUNCTION
                    cout << "\n ***" << value << "*** \n"; ///CHECK
                        if (tab[value] == "-1") {
                            tab[value] = surname;
                            break;
                        }
                        else {
                            value++;
                            while (tab[value] != "-1") {
                                value++;
                                if (value >= 100)
                                    value = 0;
                            }
                            tab[value] = surname;
                        }
                    break;
                }
            case 2:
                {
                    for (i = 0; i < SIZE; i++)
                        cout << i << " ---> " << tab[i] << endl;
                    break;
                }
            case 0: exit(0);
            default: "There is no match for this value. Try again.";
        }
    }
    return 0;
}
