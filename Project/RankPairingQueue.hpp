#pragma once

#include "RankedRootsList.hpp"
#include "IPriorityQueue.hpp"
#include <stdexcept>

namespace PriorityQueue
{
    class RankPairingQueue : public Abstract::Interfaces::IPriorityQueue
    {
    public:

        class empty_queue : public std::runtime_error
        {
        public:

            empty_queue(std::string message): std::runtime_error{ message } { };
        };

    public:
        
        RankPairingQueue() = default;
        RankPairingQueue(RankPairingQueue const&) = delete;
        RankPairingQueue(RankPairingQueue&&) = delete;

        RankPairingQueue& operator=(RankPairingQueue const&) = delete;
        RankPairingQueue& operator=(RankPairingQueue&&) = delete;

        virtual ~RankPairingQueue();

        virtual void insert(Abstract::Interfaces::IPriorityElement& element) override;
        virtual Abstract::Interfaces::IPriorityElement const& minimum() const override;
        virtual void extract_min() override;
        virtual void decrease_key(Abstract::Interfaces::IPriorityElement const& data, unsigned priority);

    private:
        
        void push_to_heap(Abstract::MeldableRankedBinaryTree* new_root) noexcept;
        void split_and_push_to_heap(Abstract::MeldableRankedBinaryTree* tree) noexcept;

    private:

        Abstract::Interfaces::IRankedRootsList* heap{ new Auxiliry::RankedRootsList{} };
    };
}