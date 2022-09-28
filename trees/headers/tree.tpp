#include "./tree.h"

template <typename T>
Node<T>::Node(Node *Parent, T value)
{
    this->Parent = Parent;
    this->value = value;
    if (Parent != NULL)
    {
        Parent->addChild(this);
    }
};