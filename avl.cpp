#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    int balance = 0;
    int l_height = 0;
    int r_height = 0;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val) : val(val){};
    void updateLeft(Node *left) { this->left = left; }
    void updateRight(Node *right) { this->right = right; }
};

class AVL
{
    Node *rightRotate(Node *n)
    {
        
    }
    Node *leftRotate(Node *n)
    {
    }

public:
    Node *head = NULL;
    Node *insert(int val);
};