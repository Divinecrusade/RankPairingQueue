#pragma once

#include "Detail.hpp"
#include "ForwardList.hpp"
#include "RootsList.hpp"

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

        ~RankPairingQueue() = default;

        void insert(Detail const& element);
        Detail const& minimum() const;
        void extract_min();
//        void decrease_key(int data, unsigned priority);

    private:
        
        Auxiliry::RootsList heap{};
    };
}