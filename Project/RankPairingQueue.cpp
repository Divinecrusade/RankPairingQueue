#include "RankPairingQueue.hpp"

void PriorityQueue::RankPairingQueue::insert(Detail const& element)
{
    if (heap.is_empty()) heap.set_first(element);
    else
    {
        if (heap.get_first()->get_minimum().get_priority() > element.get_priority()) heap.set_first(element);
        else heap.set_second(element);

        heap.unite_roots_with_same_ranks();
    }
}

Detail const& PriorityQueue::RankPairingQueue::minimum() const
{
    if (heap.is_empty()) throw std::runtime_error{ "Queue is empty" };
    else return heap.get_first()->get_minimum();
}

void PriorityQueue::RankPairingQueue::extract_min()
{
    auto new_roots{ heap.get_first()->remove_minimum() };
    if (heap.get_first()->is_empty()) heap.remove_first();
    if (!new_roots.empty())
    {
        for (auto& new_root : new_roots)
        {
            new_root->update_rank();
            heap.insert_root(new_root);
        }
        heap.unite_roots_with_same_ranks();
    }
}
