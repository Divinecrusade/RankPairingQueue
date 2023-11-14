#pragma once

#include "Detail.hpp"
#include "ForwardList.hpp"

namespace PriorityQueue
{
    class RankPairingQueue
    {
    public:
        
        RankPairingQueue() = default;
        RankPairingQueue(RankPairingQueue const&) = delete;
        RankPairingQueue(RankPairingQueue&&) = delete;

        RankPairingQueue& operator=(RankPairingQueue const&) = delete;
        RankPairingQueue& operator=(RankPairingQueue&&) = delete;

        virtual ~RankPairingQueue();

        virtual void insert(Detail const* element) = 0;
        virtual Detail const* minimum() const = 0;
        virtual Detail* extract_min() = 0;
        virtual void decrease_key(int data, unsigned priority) = 0;
        virtual void meld(RankPairingQueue* rpq) = 0;

    private:
        
        //Auxiliry::ForwardList<Auxiliry::BinaryHalfTree<Type>>* heap;
    };
}