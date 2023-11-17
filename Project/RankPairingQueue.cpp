#include "RankPairingQueue.hpp"
#include "RankedHalfBinaryTree.hpp"
#include <stdexcept>

void PriorityQueue::RankPairingQueue::insert(Interfaces::IPriorityElement& element)
{
    Auxiliry::RankedHalfBinaryTree* new_root{ new Auxiliry::RankedHalfBinaryTree{ element } };
    if (heap.is_empty()) heap.set_first(*new_root);
    else
    {
        if (heap.get_first().get_data().get_priority() >= element.get_priority()) heap.set_first(*new_root);
        else heap.set_second(*new_root);
    }
}

PriorityQueue::Interfaces::IPriorityElement const& PriorityQueue::RankPairingQueue::minimum() const
{
    if (heap.is_empty()) throw std::runtime_error{ "Queue is empty" };
    else return heap.get_first().get_data();
}

void PriorityQueue::RankPairingQueue::extract_min()
{
    Interfaces::IRankedBinaryTree& tree{ heap.remove_first() };
    Interfaces::IRankedRootsList& new_roots{ tree.remove() };

    // new_roots.get_first -> heap.set_first -> new_roots.remove_first
    // heap.unite
    // delete treee
}
