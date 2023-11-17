#include "RankedHalfBinaryTree.hpp"
#include <cassert>

PriorityQueue::Auxiliry::RankedHalfBinaryTree::RankedHalfBinaryTree(Interfaces::IPriorityElement& data) : data{ data }
{ }

void PriorityQueue::Auxiliry::RankedHalfBinaryTree::meld(IRankedBinaryTree& another_root)
{
    assert(another_root.is_root() && this->is_root());
    assert(this->get_data().get_priority() < another_root.get_data().get_priority());
    
    //another_root.bind_right(*left);
}

unsigned PriorityQueue::Auxiliry::RankedHalfBinaryTree::get_rank() const noexcept
{
    return rank;
}

void PriorityQueue::Auxiliry::RankedHalfBinaryTree::update_rank() noexcept
{
    rank = (left != nullptr ? (left->update_rank(), left->get_rank()) : 0U) + 
           (right != nullptr ? (right->update_rank(), right->get_rank()) : 0U) +
           (parent != nullptr ? 0U : 1U);
}

PriorityQueue::Interfaces::IPriorityElement const& PriorityQueue::Auxiliry::RankedHalfBinaryTree::get_data() const noexcept
{
    return data;
}

PriorityQueue::Interfaces::IPriorityElement& PriorityQueue::Auxiliry::RankedHalfBinaryTree::get_data() noexcept
{
    return data;
}

PriorityQueue::Interfaces::IRankedRootsList& PriorityQueue::Auxiliry::RankedHalfBinaryTree::remove()
{
    // TODO: вставьте здесь оператор return
}

bool PriorityQueue::Auxiliry::RankedHalfBinaryTree::is_root() const noexcept
{
    return parent == nullptr;
}
