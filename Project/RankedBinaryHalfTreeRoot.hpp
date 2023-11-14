#pragma once

#include "ForwardList.hpp"
#include "RankedBinaryTree.hpp"

namespace PriorityQueue
{
    class RankedBinaryHalfTreeRoot
    {
    public:

        RankedBinaryHalfTreeRoot() = delete;
        RankedBinaryHalfTreeRoot(int id, unsigned priority) : minimum{ new Auxiliry::ForwardList{} }
        {
            minimum->insert_back(id, priority);
        }
        RankedBinaryHalfTreeRoot(RankedBinaryHalfTreeRoot const&) = delete;
        RankedBinaryHalfTreeRoot(RankedBinaryHalfTreeRoot&&) = delete;

        RankedBinaryHalfTreeRoot& operator=(RankedBinaryHalfTreeRoot const&) = delete;
        RankedBinaryHalfTreeRoot& operator=(RankedBinaryHalfTreeRoot&&) = delete;


        void meld(RankedBinaryHalfTreeRoot* root) noexcept { }
        
        unsigned get_rank() const noexcept
        {
            return rank;
        }
        void update_rank() noexcept
        {
            rank = tree->get_rank() + 1U;
        }

        Detail const& get_minimum() const noexcept
        {
            return minimum->get(0U);
        }

    private:

        unsigned rank{ 0U };
        Auxiliry::RankedBinaryTree* tree{ nullptr };
        Auxiliry::ForwardList* minimum;
    };
}