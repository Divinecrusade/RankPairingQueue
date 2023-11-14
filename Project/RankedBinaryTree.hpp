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
        
            BinaryTree() = delete;
            BinaryTree(Interfaces::IPriorityElement<Type>& element);
            BinaryTree(BinaryTree const&) = delete;
            BinaryTree(BinaryTree&&) = delete;

            BinaryTree& operator=(BinaryTree const&) = delete;
            BinaryTree& operator=(BinaryTree&&) = delete;
        
            ~BinaryTree();


            BinaryTree<Type>* get_left() noexcept
            {
                return left;
            }
            BinaryTree<Type>* get_right() noexcept
            {
                return right;
            }

            void bind_left(BinaryTree<Type>* root) noexcept
            {
                assert(!root->parent);
                assert(!left);

                left = root;
                root->parent = this;
            }
            void bind_right(BinaryTree<Type>* root) noexcept
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

            BinaryTree<Type>*& get_parent_ptr_on_me() noexcept
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

            BinaryTree<Type>* left{ nullptr };
            BinaryTree<Type>* right{ nullptr };
            BinaryTree<Type>* parent{ nullptr };
            unsigned rank{ 0U };

            Interfaces::IList<Interfaces::IPriorityElement<Type>&>* data{ nullptr };
        };
    }
}