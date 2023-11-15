#include "RootsList.hpp"

PriorityQueue::Auxiliry::RootsList::~RootsList()
{
    if (!first) return;

    Node* tmp{ nullptr };
    while (first)
    {
        tmp = first->next;
        delete first;
        first = tmp;
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

void PriorityQueue::Auxiliry::RootsList::insert_root(RBHalfTreeRoot* new_root) noexcept
{
    if (first == nullptr) first = new Node{ new_root };
    else
    if (new_root->get_minimum().get_priority() < first->root->get_minimum().get_priority())
    {
        first = new Node{ new_root, first->next };
    }
    else
    {
        first->next = new Node{ new_root, first->next };
    }
}

PriorityQueue::RBHalfTreeRoot* PriorityQueue::Auxiliry::RootsList::get_first() const noexcept
{
    assert(first);

    return first->root;
}

PriorityQueue::RBHalfTreeRoot* PriorityQueue::Auxiliry::RootsList::get_second() const noexcept
{
    assert(first);
    assert(first->next);

    return first->next->root;
}

void PriorityQueue::Auxiliry::RootsList::unite_roots_with_same_ranks()
{
    if (!first || (first && !first->next)) return;

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
            cur = cur->next;
        }
        prev_fixed = fixed;
        fixed = fixed->next;
    }
}

bool PriorityQueue::Auxiliry::RootsList::is_empty() const noexcept
{
    return first == nullptr;
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
        if (first == node2) first = node2->next;
        else prev2->next = node2->next;
        delete node2;
    }
    else
    {
        node2->root->meld(*node1->root);
        if (first == node1) first = node1->next;
        else prev1->next = node1->next;
        delete node1;
    }
}
