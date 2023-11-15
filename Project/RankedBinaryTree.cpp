#include "RankedBinaryTree.hpp"

PriorityQueue::Auxiliry::RankedBinaryTree::RankedBinaryTree(Detail const& some_detail) : data{ new ForwardList{ } }
{
    data->insert_front(some_detail);
}

PriorityQueue::Auxiliry::RankedBinaryTree::~RankedBinaryTree()
{
    delete left;
    delete right;
    delete data;
    left = right = nullptr;
    data = nullptr;
}

PriorityQueue::Auxiliry::RankedBinaryTree* PriorityQueue::Auxiliry::RankedBinaryTree::get_left() noexcept
{
    return left;
}

PriorityQueue::Auxiliry::RankedBinaryTree* PriorityQueue::Auxiliry::RankedBinaryTree::get_right() noexcept
{
    return right;
}

void PriorityQueue::Auxiliry::RankedBinaryTree::bind_left(RankedBinaryTree* root) noexcept
{
    left = root;
    if (root) root->parent = this;
}

void PriorityQueue::Auxiliry::RankedBinaryTree::bind_right(RankedBinaryTree* root) noexcept
{
    right = root;
    if (root) root->parent = this;
}

void PriorityQueue::Auxiliry::RankedBinaryTree::remove() noexcept
{
    if (parent)
    {
        get_parent_ptr_on_me() = nullptr;
    }
    if (left) left->parent = nullptr;
    if (right) right->parent = nullptr;
}

unsigned PriorityQueue::Auxiliry::RankedBinaryTree::get_rank() const noexcept
{
    return rank;
}

void PriorityQueue::Auxiliry::RankedBinaryTree::update_rank() noexcept
{
    if (!left && !right) rank = 0U;
    else
    {
        unsigned left_rank = (!left ? 0U : left->get_rank());
        unsigned right_rank = (!right ? 0U : right->get_rank());

        rank = std::max(left_rank, right_rank) + ((std::max(left_rank, right_rank) - std::min(left_rank, right_rank) <= 1U) ? 1U : 0U);
    }
}

PriorityQueue::Auxiliry::RankedBinaryTree* PriorityQueue::Auxiliry::RankedBinaryTree::unbind_right() noexcept
{
    RankedBinaryTree* tmp{ right };
    if (right) right->parent = nullptr;
    right = nullptr;
    return tmp;
}

PriorityQueue::Auxiliry::ForwardList*& PriorityQueue::Auxiliry::RankedBinaryTree::get_data() noexcept
{
    return data;
}

PriorityQueue::Auxiliry::RankedBinaryTree*& PriorityQueue::Auxiliry::RankedBinaryTree::get_parent_ptr_on_me() noexcept
{
    assert(parent);
    assert(parent->left == this || parent->right == this);

    if (parent->left == this)
    {
        return parent->left;
    }
    else
    {
        return parent->right;
    }
}
