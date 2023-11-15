#pragma once

#include <vector>
#include "ForwardList.hpp"
#include "RankedBinaryTree.hpp"

namespace PriorityQueue
{
    class RBHalfTreeRoot
    {
    public:

        RBHalfTreeRoot() = delete;
        RBHalfTreeRoot(Detail const& some_detail);
        RBHalfTreeRoot(RBHalfTreeRoot const&) = delete;
        RBHalfTreeRoot(RBHalfTreeRoot&&) = delete;

        RBHalfTreeRoot& operator=(RBHalfTreeRoot const&) = delete;
        RBHalfTreeRoot& operator=(RBHalfTreeRoot&&) = delete;

        ~RBHalfTreeRoot() = default;

        void meld(RBHalfTreeRoot& root);
        
        unsigned get_rank() const noexcept;
        void update_rank() noexcept;

        Detail const& get_minimum() const noexcept;

        std::vector<PriorityQueue::RBHalfTreeRoot*> remove_minimum();

        bool is_empty() const noexcept;

    private:

        RBHalfTreeRoot(Auxiliry::RankedBinaryTree* node);

    private:

        unsigned rank{ 0U };
        Auxiliry::RankedBinaryTree* tree{ nullptr };
        Auxiliry::ForwardList* minimum;
    };
}