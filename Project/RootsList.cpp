#include "RootsList.hpp"

PriorityQueue::Auxiliry::RootsList::~RootsList()
{
    if (!first) return;

    Node* tmp{ first->next };
    while (first)
    {
        delete first;
        first = tmp;
        tmp = first->next;
    }
    delete first;
    first = nullptr;
}

void PriorityQueue::Auxiliry::RootsList::set_first(Detail const& some_detail) noexcept
{
    Node* new_node{ new Node{ new RBHalfTreeRoot{ some_detail } } };
    new_node->next = first;
    first = new_node;
}

void PriorityQueue::Auxiliry::RootsList::set_second(Detail const& some_detail) noexcept
{
    assert(first);

    Node* new_node{ new Node{ new RBHalfTreeRoot{ some_detail } } };
    new_node->next = first->next;
    first->next = new_node;
}

PriorityQueue::RBHalfTreeRoot* PriorityQueue::Auxiliry::RootsList::get_first() noexcept
{
    assert(first);

    return first->root;
}

PriorityQueue::RBHalfTreeRoot* PriorityQueue::Auxiliry::RootsList::get_second() noexcept
{
    assert(first);
    assert(first->next);

    return first->next->root;
}

void PriorityQueue::Auxiliry::RootsList::unite_roots_with_same_ranks()
{
    Node* fixed{ first };
    Node* prev_fixed{ nullptr };

    while (fixed)
    {
        Node* cur{ fixed->next };
        Node* prev_cur{ fixed };
        while (cur)
        {
            if (cur->root->get_rank() == fixed->root->get_rank())
            {
                unite(prev_cur, cur, fixed, prev_fixed);

                fixed = first;
                break;
            }
        }
        prev_fixed = fixed;
        fixed = fixed->next;
    }
}

void PriorityQueue::Auxiliry::RootsList::set_first(Node* new_node) noexcept
{
    new_node->next = first;
    first = new_node;
}

void PriorityQueue::Auxiliry::RootsList::set_second(Node* new_node) noexcept
{
    assert(first);

    new_node->next = first->next;
    first->next = new_node;
}

void PriorityQueue::Auxiliry::RootsList::unite(Node* prev1, Node* node1, Node* node2, Node* prev2)
{
    assert(node1->root->get_rank() == node2->root->get_rank());

    if (node1->root->get_minimum().get_priority() < node2->root->get_minimum().get_priority())
    {
        node1->root->meld(*node2->root);
        prev2->next = node2->next;
        if (first == node2) first = node2->next;
        delete node2;
    }
    else
    {
        node2->root->meld(*node1->root);
        prev1->next = node1->next;
        if (first == node1) first = node1->next;
        delete node1;
    }
}
