#pragma once
#include <bits/stdc++.h>
template <typename T>
class Node
{

public:
    Node *Parent;
    T value;
    std::list<Node *> children;
    Node(Node *Parent, T value);
    bool addChild(Node *Child)
    {
        this->children.push_back(Child);
        return true;
    }
};

#include "./tree.tpp"
