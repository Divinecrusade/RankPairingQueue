#include "RankPairingQueue.hpp"
#include "RankedHalfBinaryTree.hpp"

PriorityQueue::RankPairingQueue::~RankPairingQueue()
{
    delete heap;
}

void PriorityQueue::RankPairingQueue::insert(Abstract::Interfaces::IPriorityElement& element)
{
    Auxiliry::RankedHalfBinaryTree* new_root{ new Auxiliry::RankedHalfBinaryTree{ element } };
    push_to_heap(new_root);
    heap->unite_trees_with_same_rank();
}

PriorityQueue::Abstract::Interfaces::IPriorityElement const& PriorityQueue::RankPairingQueue::minimum() const
{
    if (heap->is_empty()) throw empty_queue{ "Queue is empty" };
    else return heap->get_first().get_data();
}

void PriorityQueue::RankPairingQueue::extract_min()
{
    Abstract::MeldableRankedBinaryTree* tree{ heap->remove_first() };
    Abstract::MeldableRankedBinaryTree* left_root{ tree->remove_left_subtree() };
    delete tree;

    if (left_root)
    {
        split_and_push_to_heap(left_root);

        heap->unite_trees_with_same_rank();
    }
}

void PriorityQueue::RankPairingQueue::decrease_key(Abstract::Interfaces::IPriorityElement const& data, unsigned priority)
{
    Abstract::MeldableRankedBinaryTree* new_root{ heap->extract_subtree(data) };

    new_root->get_data().set_priority(priority);

    push_to_heap(new_root);

    heap->unite_trees_with_same_rank();
}

void PriorityQueue::RankPairingQueue::push_to_heap(Abstract::MeldableRankedBinaryTree* new_root) noexcept
{
    if (heap->is_empty()) heap->set_first(new_root);
    else
    {
        if (heap->get_first().get_data().get_priority() >= new_root->get_data().get_priority()) heap->set_first(new_root);
        else heap->set_second(new_root);
    }
}

void PriorityQueue::RankPairingQueue::split_and_push_to_heap(Abstract::MeldableRankedBinaryTree* tree) noexcept
{
    if (!tree) return;
    
    split_and_push_to_heap(tree->remove_right_subtree());

    push_to_heap(tree);
}
