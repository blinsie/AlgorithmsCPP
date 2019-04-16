#include <iostream>
#include <vector>
#define SIZE 10

using namespace std;

int main()
{
    const int INF = 1000000000; int start = 7;
    vector<int> dist(SIZE, INF); vector<bool> visited(SIZE, false);
    int index, i, j, u;
    int g[SIZE][SIZE] = {{INF,  10,  INF, 21,  INF, 13,  INF, INF,  INF, INF},
                         {10,   INF, 15,  9,   INF, INF, INF, INF,  INF, INF},
                         {INF,  15,  INF, 6,   INF, INF, 3,   20,   INF, INF},
                         {21,   9,   6,   INF, 5,   INF, INF, INF,  INF, INF},
                         {INF,  INF, INF, 5,   INF, 7,   INF, INF,  INF, 24 },
                         {13,   INF, INF, INF, 7,   INF, INF, INF,  INF, INF},
                         {INF,  INF, 3,   INF, INF, INF, INF, INF,  14,  INF},
                         {INF,  INF, 20,  INF, INF, INF, INF, INF,  18,  11},
                         {INF,  INF, INF, INF, INF, INF, 14,  18,   INF, 4},
                         {INF,  INF, INF, INF, 24,  INF, INF, 11,   4,   INF}};
    dist[start] = 0; int min;
    for (j = 0; j < SIZE; j++)
    {
        min = INF;
        for (i = 0; i < SIZE; i++)
        if (!visited[i] && dist[i] <= min)
            {
                min = dist[i]; index = i;
                cout << "*** " << dist[i] << " *** " << index << endl;
            }
        cout << "here!" << endl;
        u = index;
        visited[u] = true;
        for (i = 0; i < SIZE; i++)
            if ((!visited[i]) && (g[u][i]) && (dist[u]!=INF) && ((dist[u] + g[u][i]) < (dist[i])))
            {
                ///dist[i]  - расст. до вершины, в к-рую можно попасть через u
                ///dist[u] - расстояние до текущей вершины
                dist[i] = dist[u] + g[u][i];
                for (int k = 0; k < SIZE; k++)
                    cout << dist[k] << " ";
                cout << endl << i << endl;
            }
                for (int k = 0; k < SIZE; k++)
                    cout << visited[k] << " "; cout << endl;
        cout << "finish!\n" << endl;
    }

    cout << "Стоимость пути из начальной вершины до остальных: \n";
    for (i = 0; i < SIZE; i++)
        if (dist[i]!=INF)
            cout << start << " & " << i << " = " << dist[i] << endl;
    return 0;
}
