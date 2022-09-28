#include <bits/stdc++.h>
#include "../headers/tree.h"
#include "../headers/traversals.h"

// template class Node<int>
typedef Node<int> ni;

int main()
{
    using namespace std;
    ni *root = new ni(NULL, 0);
    ni *node_1 = new ni(root, 1);
    ni *node_2 = new ni(root, 2);
    ni *node_3 = new ni(node_1, 3);
    ni *node_4 = new ni(node_1, 4);
    cout << "start" << endl;
    preorder(root);
    cout << "preorder done" << endl;
    postorder(root);
    cout << "postorder done" << endl;
    inorder(root);
    cout << "inorder done" << endl;
}