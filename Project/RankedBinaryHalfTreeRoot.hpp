#pragma once

#include "IPriorityElement.hpp"
#include "ForwardList.hpp"
#include "RankedBinaryTree.hpp"

namespace PriorityQueue
{
    template<std::equality_comparable Type>
    class RankedBinaryHalfTreeRoot
    {
    public:

        RankedBinaryHalfTreeRoot() = delete;
        RankedBinaryHalfTreeRoot(Interfaces::IPriorityElement<Type>* element);
        RankedBinaryHalfTreeRoot(RankedBinaryHalfTreeRoot const&) = delete;
        RankedBinaryHalfTreeRoot(RankedBinaryHalfTreeRoot&&) = delete;

        RankedBinaryHalfTreeRoot& operator=(RankedBinaryHalfTreeRoot const&) = delete;
        RankedBinaryHalfTreeRoot& operator=(RankedBinaryHalfTreeRoot&&) = delete;


        void meld(RankedBinaryHalfTreeRoot<Type>* root) noexcept;
        
        unsigned get_rank() const noexcept
        {
            return rank;
        }
        void update_rank() noexcept
        {
            rank = tree.get_rank() + 1U;
        }

        Interfaces::IPriorityElement<Type>* get_minimum() noexcept
        {
            return minimum->get(0U);
        }

        Interfaces::IList<RankedBinaryHalfTreeRoot<Type>*>* extract() noexcept;

    private:

        unsigned rank{ 0U };
        Auxiliry::RankedBinaryTree<Type> tree;
        Interfaces::IList<Interfaces::IPriorityElement<Type>*>* minimum;
    };
}