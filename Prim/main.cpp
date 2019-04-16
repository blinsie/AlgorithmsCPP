#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
int n = 10;
const int INF = 1000000000;
int g[n][n] = { {INF, 10,  INF,  21,  INF, 13, INF, INF,  INF, INF},
                {10,  INF, 15,   9,   INF, INF, INF, INF,  INF, INF},
                {INF, 15,  INF,  6,   INF, INF, 3, 20,  INF, INF},
                {21,  9,   6,    INF, 5,   INF, INF, INF,  INF, INF},
                {INF, INF, INF,  5,   INF, 7, INF, INF,  INF, 24 },
                {13,  INF, INF,  INF, 7,  INF, INF, INF,  INF, INF},
                {INF,  INF, 3,  INF, INF,  INF, INF, INF,  14, INF},
                {INF,  INF, 20,  INF, INF,  INF, INF, INF,  18, 11},
                {INF,  INF, INF,  INF, INF,  INF, 14, 18,  INF, 4},
                {INF,  INF, INF,  INF, 24,  INF, INF, 11,  4, INF}};

vector<bool> used (n);
vector<int> min_e (n, INF), sel_e (n, -1);
min_e[0] = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;

        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
              {
                 v = j;
                 cout << "here" << v << " ";
              }
        cout <<endl;
        if (min_e[v] == INF)
            {
                cout << "No MST!";
                exit(0);
            }

        used[v] = true;

        for (int to=0; to<n; ++to)
        {

            if (g[v][to] < min_e[to])
                {
                    min_e[to] = g[v][to]; ///при выборе новой вершины массив перестраивается
                    sel_e[to] = v;
                }
        }
        for (int q=0; q<n; q++)
        {
            cout << " " << min_e[q];
        }
        cout << endl;
        cout << "finish! " << endl;
        if (sel_e[v] != -1)
            cout << v << " " << sel_e[v] << endl;
    }
    return 0;
}
