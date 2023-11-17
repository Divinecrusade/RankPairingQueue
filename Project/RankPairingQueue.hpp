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

        virtual ~RankPairingQueue() = default;

        virtual void insert(Interfaces::IPriorityElement& element) override;
        virtual Interfaces::IPriorityElement const& minimum() const override;
        virtual void extract_min() override;
        //virtual void decrease_key(Type const& data, unsigned priority) = 0;

    private:
        
        Interfaces::IRankedRootsList& heap;
    };
}