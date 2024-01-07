#include "RankedBinaryTree.hpp"

PriorityQueue::Abstract::RankedBinaryTree::RankedBinaryTree(Abstract::Interfaces::IPriorityElement& data) : data{ data }
{ }

unsigned PriorityQueue::Abstract::RankedBinaryTree::get_rank() const noexcept
{
    return rank;
}

PriorityQueue::Abstract::Interfaces::IPriorityElement const& PriorityQueue::Abstract::RankedBinaryTree::get_data() const noexcept
{
    return data;
}

PriorityQueue::Abstract::Interfaces::IPriorityElement& PriorityQueue::Abstract::RankedBinaryTree::get_data() noexcept
{
    return data;
}

void PriorityQueue::Abstract::RankedBinaryTree::update_rank() noexcept
{
    rank = (get_left() != nullptr ? (get_left()->update_rank(), get_left()->get_rank()) : 0U) +
           (get_right() != nullptr ? (get_right()->update_rank(), get_right()->get_rank()) : 0U) +
           (get_parent() != nullptr ? 0U : 1U);
}
