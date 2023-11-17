#include "MeldableRankedBinaryTree.hpp"
#include <cassert>

PriorityQueue::Abstract::MeldableRankedBinaryTree::MeldableRankedBinaryTree(Interfaces::IPriorityElement& data)
    :
    PriorityQueue::Abstract::RankedBinaryTree{ data }
{ }

PriorityQueue::Abstract::MeldableRankedBinaryTree::~MeldableRankedBinaryTree()
{
    if (parent) get_parent_ptr_on_me() = nullptr;

    delete left;
    delete right;
}

PriorityQueue::Abstract::MeldableRankedBinaryTree* PriorityQueue::Abstract::MeldableRankedBinaryTree::remove_left_subtree() noexcept
{
    MeldableRankedBinaryTree* left_subtree{ left };

    if (left) left->parent = nullptr;
    left = nullptr;

    return left_subtree;
}

PriorityQueue::Abstract::MeldableRankedBinaryTree* PriorityQueue::Abstract::MeldableRankedBinaryTree::remove_right_subtree() noexcept
{
    MeldableRankedBinaryTree* right_subtree{ right };

    if (right) right->parent = nullptr;
    right = nullptr;

    return right_subtree;
}

bool PriorityQueue::Abstract::MeldableRankedBinaryTree::is_root() const noexcept
{
    return parent == nullptr;
}

PriorityQueue::Abstract::MeldableRankedBinaryTree*& PriorityQueue::Abstract::MeldableRankedBinaryTree::get_parent_ptr_on_me() const noexcept
{
    assert(parent);
    assert(left == this || right == this);

    return (parent->left == this ? parent->left : parent->right);
}

PriorityQueue::Abstract::RankedBinaryTree const* PriorityQueue::Abstract::MeldableRankedBinaryTree::get_left() const noexcept
{
    return left;
}

PriorityQueue::Abstract::RankedBinaryTree* PriorityQueue::Abstract::MeldableRankedBinaryTree::get_left() noexcept
{
    return left;
}

PriorityQueue::Abstract::RankedBinaryTree const* PriorityQueue::Abstract::MeldableRankedBinaryTree::get_right() const noexcept
{
    return right;
}

PriorityQueue::Abstract::RankedBinaryTree* PriorityQueue::Abstract::MeldableRankedBinaryTree::get_right() noexcept
{
    return right;
}

PriorityQueue::Abstract::RankedBinaryTree const* PriorityQueue::Abstract::MeldableRankedBinaryTree::get_parent() const noexcept
{
    return parent;
}

PriorityQueue::Abstract::RankedBinaryTree* PriorityQueue::Abstract::MeldableRankedBinaryTree::get_parent() noexcept
{
    return parent;
}

void PriorityQueue::Abstract::MeldableRankedBinaryTree::bind_left(MeldableRankedBinaryTree* root)
{
    assert(!left);
    assert(!root || (root && !root->parent));

    left = root;
}

void PriorityQueue::Abstract::MeldableRankedBinaryTree::bind_right(MeldableRankedBinaryTree* root)
{
    assert(!right);
    assert(!root || (root && !root->parent));

    right = root;
}

