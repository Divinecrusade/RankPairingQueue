#pragma once

#include "IRankedRootsList.hpp"
#include "IPriorityQueue.hpp"

namespace PriorityQueue
{
    class RankPairingQueue : public Interfaces::IPriorityQueue
    {
    public:
        
        RankPairingQueue() = default;
        RankPairingQueue(RankPairingQueue const&) = delete;
        RankPairingQueue(RankPairingQueue&&) = delete;

        RankPairingQueue& operator=(RankPairingQueue const&) = delete;
        RankPairingQueue& operator=(RankPairingQueue&&) = delete;

        virtual ~RankPairingQueue();

        virtual void insert(Interfaces::IPriorityElement const& element) = 0;
        virtual Interfaces::IPriorityElement const& minimum() const = 0;
        virtual void extract_min() = 0;
        //virtual void decrease_key(Type const& data, unsigned priority) = 0;

    private:
        
        Interfaces::IRankedRootsList* heap;
    };
}