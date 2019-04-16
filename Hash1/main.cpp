#include <iostream>
#include <ctime>
#include<stdlib.h>

using namespace std;


int find_col(int a[], int s, int n)
{
    int x, y; int a_hash[s]; int counter = 0;
    cout << "Hash: ";
    for (x = 0; x < s; x++) {
       a_hash[x] = a[x] % n;
       cout << a_hash[x] << " ";
    } cout << endl;

    for (x = 0; x < s-1; x++)
        for (y = x+1; y < s; y++) {
            if (a_hash[x] == a_hash[y]) {
                cout << "Collision! >> " << a[x] << " (" << a_hash[x] << ") ";
                cout << "and " << a[y] << " (" << a_hash[y] << ") \n";
                counter++;
            }
        }
    return counter;
}


int main()
{
    int size = 50; int num[8] = {10,11,16,17,32,37,64,67};
    int arr[size]; int i; int res;

    cout << "Array: ";
    for (i = 0; i < size; i++)
    {
        arr[i] = rand()*0.32 + 21;
        cout << arr[i] << " ";
    } cout << endl;

    for (i = 0; i < 8; i++){
        cout << "Using N = " << num[i] << endl;
        res = find_col(arr, size, num[i]);
        cout << "\n" << res << " collisions from 1125 cases.\n";
    }
    return 0;
}
