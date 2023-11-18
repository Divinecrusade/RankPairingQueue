#pragma once

#include "RankedBinaryTree.hpp"

namespace PriorityQueue
{
    namespace Abstract
    {
        class MeldableRankedBinaryTree : public RankedBinaryTree
        {
        public:
            
            MeldableRankedBinaryTree() = delete;
            MeldableRankedBinaryTree(Interfaces::IPriorityElement& data);
            MeldableRankedBinaryTree(MeldableRankedBinaryTree const&) = delete;
            MeldableRankedBinaryTree(MeldableRankedBinaryTree&&) = delete;

            MeldableRankedBinaryTree& operator=(MeldableRankedBinaryTree const&) = delete;
            MeldableRankedBinaryTree& operator=(MeldableRankedBinaryTree&&) = delete;

            virtual ~MeldableRankedBinaryTree();

            virtual void meld(MeldableRankedBinaryTree* tree) = 0;
            virtual MeldableRankedBinaryTree* find(Interfaces::IPriorityElement const& data) = 0;

            MeldableRankedBinaryTree* remove_left_subtree() noexcept;
            MeldableRankedBinaryTree* remove_right_subtree() noexcept;

            bool is_root() const noexcept;

            virtual void remove() override;
            virtual void attach(MeldableRankedBinaryTree* node) = 0;

            static MeldableRankedBinaryTree* get_left(MeldableRankedBinaryTree const* node) noexcept;
            static MeldableRankedBinaryTree* get_right(MeldableRankedBinaryTree const* node) noexcept;
            static MeldableRankedBinaryTree* get_parent(MeldableRankedBinaryTree const* node) noexcept;

            void update_rank() noexcept;

        protected:

            virtual RankedBinaryTree const* get_left() const noexcept override;
            virtual RankedBinaryTree* get_left() noexcept override;
            virtual RankedBinaryTree const* get_right() const noexcept override;
            virtual RankedBinaryTree* get_right() noexcept override;
            virtual RankedBinaryTree const* get_parent() const noexcept override;
            virtual RankedBinaryTree* get_parent() noexcept override;

        public:

            void bind_left(MeldableRankedBinaryTree* root);
            void bind_right(MeldableRankedBinaryTree* root);

        private:

            MeldableRankedBinaryTree*& get_parent_ptr_on_me() const noexcept;

        private:

            MeldableRankedBinaryTree* left{ nullptr };
            MeldableRankedBinaryTree* right{ nullptr };
            MeldableRankedBinaryTree* parent{ nullptr };
        };
    }
}