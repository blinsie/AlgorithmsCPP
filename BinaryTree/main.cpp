#include <iostream>
#include <stddef.h>
#include <queue>
#include <stdlib.h>

using namespace std;

struct Tree {
            int x;
            Tree *Left,*Right;} ;
    Tree *root = NULL; Tree *tmp;

Tree* tpush(Tree *r, int data)
{
    if (r == NULL) {
        r = new Tree;
        r->x = data;
        r->Left = NULL;
        r->Right = NULL;
        return r;
    }
    else if (data < r->x)
        r->Left = tpush(r->Left, data);
    else r->Right = tpush(r->Right, data);
}

int* tfind (Tree *r, int k)
{
    if (r == NULL) {
        cout << "Can`t found element`s address." << endl;
        return NULL;
    }
   int* tmp = &(r->x);
   if (k == r->x) {cout << "\n\n" << r->x << "\n\n"; return tmp;}
   else if (k < r->x) tfind(r->Left, k);
   else tfind(r->Right, k);
}

Tree* del(Tree *r, int k)
{
    if (r == NULL) return r;

    if (k == r->x)
    {
        Tree *tmp;
        if (r->Right == NULL)
           tmp = r->Left;
        else
        {
            Tree *ptr = r->Right;
            if (ptr->Left == NULL)
            {
                ptr->Left = r->Left;
                tmp = ptr;
            }
            else
            {
               Tree *ptrmin = ptr->Left;
               while (ptrmin->Left != NULL)
               {
                   ptr = ptrmin;
                   ptrmin = ptr->Left;
               }
               ptr->Left = ptrmin->Right;
               ptrmin->Left = r->Left;
               ptrmin->Right = r->Right;
               tmp = ptrmin;
            }
        }
        delete (r);
        return tmp;
    }
    else if (k < r->x)
        r->Left = del(r->Left, k);
    else r->Right = del(r->Right, k);
    return r;

}

void preorder(Tree *r)
{
    if (r == NULL) return;
    cout << r->x << " ";
    preorder(r->Left);
    preorder(r->Right);
}

void postorder(Tree *r)
{
    if (r == NULL) return;
    postorder(r->Left);
    postorder(r->Right);
    cout << r->x << " ";
}

void inorder(Tree *r)
{
    if (r == NULL) return;
    inorder(r->Left);
    cout << r->x << " ";
    inorder(r->Right);
}

void bfs(Tree *r)
{
    queue<Tree*> q;

    if (r != NULL)
    {
       q.push(r);
       cout << r->x << " ";
    }
    else
       {
         cout << "NULL ";
         return;
       }

    while (!q.empty())
    {
       Tree *tmp = q.front(); q.pop();
       if (tmp->Left != NULL) {
            q.push(tmp->Left);
            cout << tmp->Left->x << " ";
       } else {
            cout << "NULL ";
       }
       if (tmp->Right != NULL) {
            q.push(tmp->Right);
            cout << tmp->Right->x << " ";
       } else {
            cout << "NULL ";
       }
    }
}


int main()
{
    int menu, menu1;
    int value; int usekey; int* ans;
    bool flag = true;
    while (true) {
        cout << "1. Add value to the tree.";
        cout << "\n2. Delete value from the tree by key.\n";
        cout << "3. Print tree.\n";
        cout << "4. Print address of element by key.\n";
        cout << "0. Exit.\n";
        cout << "Make decision: "; cin >> menu; cout << endl;
        switch (menu) {
        case 1 : {
                    cout << "Input value:  "; cin >> value;
                    cout << endl;
                    tmp = tpush(root, value);
                    if (root == NULL) root = tmp;
                    break;
                 }

        case 2 : {
                    cout << "Input deleting key: "; cin >> usekey;
                    cout << "Deleting...\n";
                    root = del(root, usekey);
                    break;
                 }
        case 3 : {
                    cout << "Show tree as: \n"; flag = true;
                    while (flag) {
                        cout << "   1. Pre-order.\n";
                        cout << "   2. Post-order.\n";
                        cout << "   3. In-order.\n";
                        cout << "   4. BFS.\n";
                        cout << "   0. Exit.\n";
                        cout << "Make decision: ";
                        cin >> menu1; cout << endl;
                        switch (menu1) {
                        case 1 : {
                                    cout << "Pre-order: ";
                                    preorder(root); cout << endl;
                                    break;
                                 }

                        case 2 : {
                                    cout << "Post-order: ";
                                    postorder(root); cout << endl;
                                    break;
                                 }
                        case 3 : {
                                    cout << "In-order: ";
                                    inorder(root); cout << endl;
                                    break;
                                 }
                        case 4 : {
                                    cout << "BFS: ";
                                    bfs(root); cout << endl;
                                    break;
                                 }
                        case 0 : { flag = false; break; }

                        default: cout << "The is no matching for this value. Try again.\n";

                        }///switch
                    }///while
                    break;
                 }
        case 4 : {
                    cout << "Input key: "; cin >> usekey;
                    ans = tfind(root, usekey);
                    cout << "Address of element: " << ans << "."<< endl;
                    break;
                 }
        case 0 : { exit(0); break; }

        default: cout << "The is no matching for this value. Try again.\n";

        }

    }

    return 0;
}
