#include <bits/stdc++.h>
using namespace std;
class Node
{
    int sum;
    int begin;
    int end;

public:
    Node *left = NULL;
    Node *right = NULL;
    Node(int begin, int end) : begin(begin), end(end){};
    void updateSum(int new_sum) { this->sum = new_sum; }
    int getSum() { return sum; }
    std::pair<int, int> getRange() { return {begin, end}; }
    int getLeft() { return begin; }
    int getRight() { return end; }

    Node *addLeft();
    Node *addRight();
};

class SegementTree
{
    static int isContained(pair<int, int> parent, pair<int, int> child);
    vector<int> v;
    Node *head;
    int size;
    void populateSum();
    void __postOrder(Node *it);
    void __visit(Node *it);

    int query(int l, int r);
    // l inclusive, r exclusive

public:
    SegementTree(std::vector<int> const &v);
};

int SegementTree::isContained(pair<int, int> parent, pair<int, int> possible_child)
{
    // 0 child is super set of parent => just add node->sum() to the total
    // 1 if partly contained (0,4) is partly contained in (1,9) => go to children
    // -1 if not contained (0,4) in not contained in (4,6) => skip

    if (parent.first >= possible_child.first && parent.second <= possible_child.second)
        return 0;

    if (parent.first <= possible_child.first || parent.second >= possible_child.second)
        return 1;

    return -1;
}

void SegementTree::populateSum()
{
    __postOrder(head);
}

void SegementTree::__postOrder(Node *it)
{
    if (it->left)
        __postOrder(it->left);
    if (it->right)
        __postOrder(it->right);

    __visit(it);
}

void SegementTree::__visit(Node *it)
{
    if (it->getRight() - it->getLeft() == 1)
        it->updateSum(v[it->getLeft()]);
    else
    {
        int l_sum = 0;
        int r_sum = 0;

        if (it->left)
            l_sum = it->left->getSum();
        if (it->left)
            r_sum = it->right->getSum();
        it->updateSum(l_sum + r_sum);
    }
}

SegementTree::SegementTree(std::vector<int> const &v)
{
    this->v = v;
    this->size = v.size();
    this->head = new Node(0, v.size());
    std::stack<Node *> rec;
    rec.push(head);
    while (rec.size() > 0)
    {
        Node *top = rec.top();
        rec.pop();
        int l = top->getLeft();
        int r = top->getRight();

        if (r - l == 1) // only one element of array is part of the node
            continue;
        int mid = (l + r) / 2;
        top->left = new Node(l, mid);
        top->right = new Node(mid, r);
        rec.push(top->left);
        rec.push(top->right);
    }
    // stack is empty
    // do post order

    populateSum();
}

int SegementTree::query(int l, int r)
{
    pair<int, int> query_range = {l, r};
    stack<Node *> rec;
    rec.push(head);
    int sum = 0;
    while (!rec.empty())
    {
        Node *top = rec.top();
        rec.pop();
        int contained_state = isContained(top->getRange(), query_range);
        if (contained_state == 0)
        {
            sum = sum + top->getSum();
        }
        else if (contained_state == 1)
        {
            int contained_state_left_child = isContained(top->left->getRange(), query_range);
            int contained_state_right_child = isContained(top->right->getRange(), query_range);
            if (contained_state_left_child != -1)
                rec.push(top->left);
            if (contained_state_right_child != -1)
                rec.push(top->right);
        }
    }
    return sum;
}