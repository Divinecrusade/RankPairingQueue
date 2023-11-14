#pragma once

#include "ForwardList.hpp"
#include "IPriorityElement.hpp"
#include <cassert>

namespace PriorityQueue
{
    namespace Auxiliry
    {
        template<std::equality_comparable Type>
        class RankedBinaryTree
        {
        public:
        
            RankedBinaryTree() = delete;
            RankedBinaryTree(Interfaces::IPriorityElement<Type>& element) : data{ new ForwardList<Type>{ } }
            {
                data->insert_front(element);
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
                left = right = data = nullptr;
            }


            RankedBinaryTree<Type>* get_left() noexcept
            {
                return left;
            }
            RankedBinaryTree<Type>* get_right() noexcept
            {
                return right;
            }

            void bind_left(RankedBinaryTree<Type>* root) noexcept
            {
                assert(!root->parent);
                assert(!left);

                left = root;
                root->parent = this;
            }
            void bind_right(RankedBinaryTree<Type>* root) noexcept
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

            RankedBinaryTree<Type>*& get_parent_ptr_on_me() noexcept
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

            RankedBinaryTree<Type>* left{ nullptr };
            RankedBinaryTree<Type>* right{ nullptr };
            RankedBinaryTree<Type>* parent{ nullptr };
            unsigned rank{ 0U };

            Interfaces::IList<Interfaces::IPriorityElement<Type>&>* data{ nullptr };
        };
    }
}