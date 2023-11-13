#pragma once

#include "IPriorityQueue.hpp"
#include "IBinaryHalfTree.hpp"
#include "ForwardList.hpp"

namespace PriorityQueue
{
    template<std::equality_comparable Type>
    class RankPairingQueue : public Interfaces::IPriorityQueue
    {
    public:
        
        RankPairingQueue() = default;
        RankPairingQueue(RankPairingQueue const&) = delete;
        RankPairingQueue(RankPairingQueue&&) = delete;

        RankPairingQueue& operator=(RankPairingQueue const&) = delete;
        RankPairingQueue& operator=(RankPairingQueue&&) = delete;

        virtual ~RankPairingQueue();

        virtual void insert(IPriorityElement<Type> const* element) = 0;
        virtual Interfaces::IPriorityElement<Type> const* minimum() const = 0;
        virtual Interfaces::IPriorityElement<Type>* extract_min() = 0;
        virtual void decrease_key(Type const& data, unsigned priority) = 0;
        virtual void meld(Interfaces::IPriorityQueue* pq) = 0;

    private:
        
        Interfaces::IForwardList<Interfaces::::IBinaryHalfTree&, Type>* heap;
    };
}