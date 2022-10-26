#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val) : val(val){};
    void updateLeft(Node *left) { this->left = left; }
    void updateRight(Node *right) { this->right = right; }
};

class BST
{
public:
    Node *head = NULL;
    Node *insertNode(int val);
    Node *searchNode(int val);
    Node *getParent(int val);
    bool deleteNode(int val);
};

Node *BST::insertNode(int val)
{
    Node *new_node = new Node(val);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    Node *it = head;
    while (true)
    {
        if (it->val == val)
            return NULL;
        else if (it->val < val)
        {
            if (it->right == NULL)
            {
                it->right = new_node;
                break;
            }
            it = it->right;
        }
        else if (it->val > val)
        {
            if (it->left == NULL)
            {
                it->left = new_node;
                break;
            }
            it = it->left;
        }
    }
    return new_node;
}

Node *BST::searchNode(int val)
{
    if (head == NULL)
        return NULL;
    Node *it = head;
    while (it != NULL)
    {
        if (it->val == val)
            return it;
        else if (it->val < val)
            it = it->right;
        else if (it->val > val)
            it = it->left;
    }
    return NULL;
}

Node *BST::getParent(int val)
{
    // NULL returned in 2 cases
    if (head == NULL)
        return NULL;
    Node *it = head;
    Node *parent = NULL;
    while (it != NULL)
    {
        if (it->val == val)
        {
            return parent;
        }
        else if (it->val < val)
        {
            parent = it;
            it = it->right;
        }
        else if (it->val > val)
        {
            parent = it;
            it = it->left;
        }
    }
    return NULL;
}

bool BST::deleteNode(int val)
{
    if (head == NULL)
        return false;
    Node *it = head;
    Node *parent = getParent(val);
    if (parent == NULL)
    {
        if (head->val != val)
            return false;
        // root to be deleted
    }

    Node *n = NULL;
    bool l = false;
    if (parent->left && parent->left->val == val)
    {
        n = parent->left;
        l = true;
    }
    if (parent->right && parent->right->val == val)
    {
        n = parent->right;
    }
    // when parent is NULL and head is not the vaue then we know no such node exists

    if (n->left == NULL && n->right == NULL)
    {
        if (l)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (n->right == NULL)
    {
        if (l)
            parent->left = n->left;
        else
            parent->right = n->left;
    }
    else
    {
        // replace with inorder next
        Node *temp = n->right;
        if (temp->left == NULL)
        {
            n->val = n->right->val;
            n->right = n->right->right;
            return true;
        }
        else
        {
            while (temp->left->left != NULL)
                temp = temp->left;
            n->val = temp->left->val;
            temp->left = NULL;
            return true;
        }
    }
}

int main()
{
    BST bst;
    bst.insertNode(5);
    bst.insertNode(3);
    bst.insertNode(2);
    bst.insertNode(4);
    bst.insertNode(7);
    bst.insertNode(1);
    bst.insertNode(6);

    cout << bst.deleteNode(3) << endl;
    return 1;
}