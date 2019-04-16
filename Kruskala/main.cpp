#include <iostream>
#include <vector>
#include <algorithm>
#define n 10
#define m 15
using namespace std;

int main()
{
    vector < vector<int> > g = {{10,0,1}, {21,0,3}, {13,0,5},
                                {15,1,2}, {9,1,3}, {6,2,3},
                                {3,2,6}, {20,2,7}, {5,3,4},
                                {7,4,5}, {24,4,9}, {14,6,8},
                                {18,7,8}, {11,7,9}, {4,8,9}};
    sort( g.begin(), g.end() );
    int cost = 0; int i, j, v1, v2, l, old_id, new_id;
    vector < pair<int,int> > res;

    vector<int> tree_id (n);
    for ( i=0; i<n; i++)
        tree_id[i] = i;

    for ( i=0; i<n; ++i)
    {
        v1 = g[i][1],  v2 = g[i][2],  l = g[i][0];
        cout << v1 << " *** " << v2 << " *** " << l << endl;
        for ( int k = 0; k < n; k++)
            cout << tree_id[k] << " ";
        cout << endl;
        if (tree_id[v1] != tree_id[v2])
        {
            cout << "!!!!here!!!!" << endl;
            cost += l;
            res.push_back (make_pair (v1, v2));
            old_id = tree_id[v2];  new_id = tree_id[v1];
            for (j=0; j<n; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
    }
     for (vector< pair<int,int> >::iterator ix = res.begin(); ix!=res.end(); ix++)
        cout << ix->first << " " << ix->second << endl;

return 0;
}
