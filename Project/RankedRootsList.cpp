#include "RankedRootsList.hpp"
#include "MeldableRankedBinaryTree.hpp"

#include <cassert>

PriorityQueue::Auxiliry::RankedRootsList::~RankedRootsList()
{
    Node* tmp{ };
    while (first)
    {
        tmp = first->next;
        delete first;
        first = tmp;
    }
}

void PriorityQueue::Auxiliry::RankedRootsList::set_first(Abstract::MeldableRankedBinaryTree* root)
{
    Node* new_node{ new Node{ root, first } };
    first = new_node;
}

void PriorityQueue::Auxiliry::RankedRootsList::set_second(Abstract::MeldableRankedBinaryTree* root)
{
    assert(!is_empty());

    Node* new_node{ new Node{ root, first->next } };
    first->next = new_node;
}

PriorityQueue::Abstract::MeldableRankedBinaryTree const& PriorityQueue::Auxiliry::RankedRootsList::get_first() const noexcept
{
    assert(!is_empty());

    return *first->root;
}

PriorityQueue::Abstract::MeldableRankedBinaryTree* PriorityQueue::Auxiliry::RankedRootsList::remove_first() noexcept
{
    assert(!is_empty());

    Abstract::MeldableRankedBinaryTree* tree{ first->root };
    first->root = nullptr;
    Node* next{ first->next };
    delete first;
    first = next;

    return tree;
}

bool PriorityQueue::Auxiliry::RankedRootsList::is_empty() const noexcept
{
    return first == nullptr;
}

void PriorityQueue::Auxiliry::RankedRootsList::unite_trees_with_same_rank()
{
    Node* fixed{ first };
    Node* prev_fixed{ nullptr };

    while (fixed)
    {
LOOP_START: 
        Node* cur{ fixed->next };
        Node* prev_cur{ fixed };

        while (cur)
        {
            if (cur->root->get_rank() == fixed->root->get_rank())
            {
                unite(prev_fixed, fixed, prev_cur, cur);

                prev_fixed = nullptr;
                fixed = first;

                goto LOOP_START;
            }
            prev_cur = cur;
            cur = cur->next;
        }
        prev_fixed = fixed;
        fixed = fixed->next;
    }
}

void PriorityQueue::Auxiliry::RankedRootsList::unite(Node* prev1, Node* node1, Node* prev2, Node* node2)
{
    assert(node1 && node2);

    if (node1->root->get_data().get_priority() < node2->root->get_data().get_priority())
    {
        node1->root->meld(node2->root);
        if (first == node2) first = node2->next;
        else prev2->next = node2->next;
        node2->root = nullptr;
        delete node2;
    }
    else
    {
        node2->root->meld(node1->root);
        if (first == node1) first = node1->next;
        else prev1->next = node1->next;
        node1->root = nullptr;
        delete node1;
    }
}
