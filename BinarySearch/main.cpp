#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

int BiSearch(int arr[], int key, int s)
{
   int first = 0; int last = s-1; int mid;

   if ((s == 0)|| (key < arr[first]) || (key > arr[last]))
    return -1;

   while ((last - first) >= 0)
   {
       mid = first + (last - first)/2; ///cout << mid << endl;
        if (key == arr[mid])
            return mid;
        else if (key > arr[mid])
            first = mid + 1;
        else
            last = mid - 1;
   }
   return -1;
}

int main()
{
    srand(time(NULL));
    const int N = 14;
    int vec[N] = {0,1,2,4,5,7,9,11,13,14,15,16,18,20};
    for (int i = 0; i < N; i++)
            cout << vec[i] << " ";
    cout << endl;

    int element;

    cout << "Input key: "; cin >> element;
    cout << endl;

    int result = BiSearch(vec, element, N);

    cout << "\nIndex of element: " << result << endl;

    return 0;
}
