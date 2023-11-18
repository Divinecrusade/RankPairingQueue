#include "RankedHalfBinaryTree.hpp"
#include <cassert>
#include <stdexcept>

PriorityQueue::Auxiliry::RankedHalfBinaryTree::RankedHalfBinaryTree(Abstract::Interfaces::IPriorityElement& data)
:
MeldableRankedBinaryTree{ data }
{ }

void PriorityQueue::Auxiliry::RankedHalfBinaryTree::meld(MeldableRankedBinaryTree* root)
{
    root->bind_right(remove_left_subtree());
    bind_left(root);
}

PriorityQueue::Abstract::MeldableRankedBinaryTree* PriorityQueue::Auxiliry::RankedHalfBinaryTree::find(PriorityQueue::Abstract::Interfaces::IPriorityElement const& data)
{
    MeldableRankedBinaryTree* node{ this };
    
    while (node &&
           !(node->get_data().get_priority() == data.get_priority() &&
           node->get_data().get_id() == data.get_id()))
    {
        if (node->get_data().get_priority() > data.get_priority()) node = MeldableRankedBinaryTree::get_right(node);
        else node = MeldableRankedBinaryTree::get_left(node);
    }

    return node;
}

void PriorityQueue::Auxiliry::RankedHalfBinaryTree::attach(MeldableRankedBinaryTree* node)
{
    assert(!get_left() || !get_right());

    if (!get_left() && get_data().get_priority() >= node->get_data().get_priority())
    {
        bind_left(node);
    }
    else
    {
        if (get_right()) throw std::runtime_error{ "Node belongs to right, but it is already occupied" };

        bind_right(node);
    }
}

void PriorityQueue::Auxiliry::RankedHalfBinaryTree::replace(MeldableRankedBinaryTree* node1, MeldableRankedBinaryTree* node2)
{
    if (MeldableRankedBinaryTree::get_left(this) == node1)
    {
        node1->remove();
        bind_left(node2);
    }
    else if (MeldableRankedBinaryTree::get_right(this) == node1)
    {
        node1->remove();
        bind_right(node2);
    }
    else throw std::runtime_error{ "Node doesnt have this child to replace" };
}
