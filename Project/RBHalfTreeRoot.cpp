#include "RBHalfTreeRoot.hpp"

PriorityQueue::RBHalfTreeRoot::RBHalfTreeRoot(Detail const& some_detail) : minimum{ new Auxiliry::ForwardList{ } }
{
    minimum->insert_back(some_detail);
}

PriorityQueue::RBHalfTreeRoot::RBHalfTreeRoot(Auxiliry::RankedBinaryTree* node) : minimum{ new Auxiliry::ForwardList{ } }
{
    assert(!node->get_right());

    minimum = node->get_data();
    node->get_data() = nullptr;
    tree = node->get_left();

    node->remove();
}
void PriorityQueue::RBHalfTreeRoot::meld(RBHalfTreeRoot& root)
{
    Auxiliry::RankedBinaryTree* new_node{ new Auxiliry::RankedBinaryTree{ root.get_minimum() } };
    new_node->bind_right(tree);
    new_node->bind_left(root.tree);
    tree = new_node;
    ++rank;
}

unsigned PriorityQueue::RBHalfTreeRoot::get_rank() const noexcept
{
    return rank;
}

void PriorityQueue::RBHalfTreeRoot::update_rank() noexcept
{
    rank = (tree != nullptr ? (tree->update_rank(), tree->get_rank()) + 1U : 0U);
}

Detail const& PriorityQueue::RBHalfTreeRoot::get_minimum() const noexcept
{
    return minimum->get(0U);
}

std::vector<PriorityQueue::RBHalfTreeRoot*> PriorityQueue::RBHalfTreeRoot::remove_minimum()
{
    minimum->remove(0U);
    if (!minimum->is_empty()) return std::vector<PriorityQueue::RBHalfTreeRoot*>{};

    std::vector<PriorityQueue::RBHalfTreeRoot*> new_roots{ };
    Auxiliry::RankedBinaryTree* subtree{ tree };
    Auxiliry::RankedBinaryTree* right_subtree{ nullptr };
    while (subtree)
    {
        right_subtree = subtree->unbind_right();
        new_roots.push_back(new RBHalfTreeRoot{ subtree });
        subtree = right_subtree;
    }

    tree = nullptr;

    return new_roots;
}

bool PriorityQueue::RBHalfTreeRoot::is_empty() const noexcept
{
    return minimum->is_empty();
}
