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
            RankedBinaryTree(int id, unsigned priority) : data{ new ForwardList{ } }
            {
                data->insert_front(id, priority);
            }
            RankedBinaryTree(RankedBinaryTree const&) = delete;
            RankedBinaryTree(RankedBinaryTree&&) = delete;

            RankedBinaryTree& operator=(RankedBinaryTree const&) = delete;
            RankedBinaryTree& operator=(RankedBinaryTree&&) = delete;
        
            ~RankedBinaryTree()
            {
                delete left;
                delete right;
                delete data;
                left = right = nullptr;
                data = nullptr;
            }


            RankedBinaryTree* get_left() noexcept
            {
                return left;
            }
            RankedBinaryTree* get_right() noexcept
            {
                return right;
            }

            void bind_left(RankedBinaryTree* root) noexcept
            {
                assert(!root->parent);
                assert(!left);

                left = root;
                root->parent = this;
            }
            void bind_right(RankedBinaryTree* root) noexcept
            {
                assert(!root->parent);
                assert(!right);

                right = root;
                root->parent = this;
            }

            void remove() noexcept
            {
                if (parent)
                {
                    get_parent_ptr_on_me() = nullptr;
                }
            }

            unsigned get_rank() const noexcept
            {
                return rank;
            }
            void update_rank() noexcept
            {
                if (!left && !right) rank = 0U;
                else
                {
                    unsigned left_rank = (!left ? 0U : left->get_rank());
                    unsigned right_rank = (!right ? 0U : right->get_rank());

                    rank = std::max(left_rank, right_rank) + ((std::max(left_rank, right_rank) - std::min(left_rank, right_rank) <= 1U) ? 1U : 0U);
                }
            }

        private:

            RankedBinaryTree*& get_parent_ptr_on_me() noexcept
            {
                assert(parent);
                assert(parent->left == this || parent->right == this);

                if (parent->left == this)
                {
                    return parent->left;
                }
                else
                {
                    return parent->right;
                }
            }

        private:

            RankedBinaryTree* left{ nullptr };
            RankedBinaryTree* right{ nullptr };
            RankedBinaryTree* parent{ nullptr };
            unsigned rank{ 0U };

            ForwardList* data{ nullptr };
        };
    }
}