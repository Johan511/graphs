#include "./traversals.h"
template <typename T>
void preorder(Node<T> *head)
{
    std::cout << head->value << std::endl;
    auto it = head->children.begin();
    while (it != head->children.end())
    {
        preorder(*it);
        it++;
    }
}

template <typename T>
void postorder(Node<T> *head)
{
    auto it = head->children.begin();
    while (it != head->children.end())
    {
        postorder(*it);
        it++;
    }
    std::cout << head->value << std::endl;
}

template <typename T>
void inorder(Node<T> *head)
{
    auto it = head->children.begin();
    while (it != head->children.end())
    {
        inorder(*it);
        std::cout << (head)->value << std::endl;

        it++;
    }
}
