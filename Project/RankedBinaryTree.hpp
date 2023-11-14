#pragma once

#include "ForwardList.hpp"
#include <cassert>

namespace PriorityQueue
{
    namespace Auxiliry
    {
        class RankedBinaryTree
        {
        public:
        
            RankedBinaryTree() = delete;
            RankedBinaryTree(Detail const& some_detail);
            RankedBinaryTree(RankedBinaryTree const&) = delete;
            RankedBinaryTree(RankedBinaryTree&&) = delete;

            RankedBinaryTree& operator=(RankedBinaryTree const&) = delete;
            RankedBinaryTree& operator=(RankedBinaryTree&&) = delete;
        
            ~RankedBinaryTree();

            RankedBinaryTree* get_left() noexcept;
            RankedBinaryTree* get_right() noexcept;

            void bind_left(RankedBinaryTree* root) noexcept;
            void bind_right(RankedBinaryTree* root) noexcept;

            void remove() noexcept;

            unsigned get_rank() const noexcept;
            void update_rank() noexcept;

            ForwardList*& get_data() noexcept;

        private:

            RankedBinaryTree*& get_parent_ptr_on_me() noexcept;

        private:

            RankedBinaryTree* left{ nullptr };
            RankedBinaryTree* right{ nullptr };
            RankedBinaryTree* parent{ nullptr };
            unsigned rank{ 0U };

            ForwardList* data{ nullptr };
        };
    }
}