#pragma once

#include "IRankedTree.hpp"

namespace PriorityQueue
{
    namespace Abstract
    {
        class RankedBinaryTree : public Interfaces::IRankedTree
        {
        public:

            RankedBinaryTree() = delete;
            RankedBinaryTree(Interfaces::IPriorityElement& data);
            RankedBinaryTree(RankedBinaryTree const&) = delete;
            RankedBinaryTree(RankedBinaryTree&&) = delete;

            RankedBinaryTree& operator=(RankedBinaryTree const&) = delete;
            RankedBinaryTree& operator=(RankedBinaryTree&&) = delete;

            virtual ~RankedBinaryTree() = default;

            virtual unsigned get_rank() const noexcept override;

            virtual Interfaces::IPriorityElement const& get_data() const noexcept override;
            virtual Interfaces::IPriorityElement& get_data() noexcept override;

            virtual void remove() = 0;

        protected:

            virtual RankedBinaryTree const* get_left() const = 0;
            virtual RankedBinaryTree* get_left() = 0;
            virtual RankedBinaryTree const* get_right() const = 0;
            virtual RankedBinaryTree* get_right() = 0;
            virtual RankedBinaryTree const* get_parent() const = 0;
            virtual RankedBinaryTree* get_parent() = 0;

            void update_rank() noexcept;

        private:

            unsigned rank{ 0U };
            Abstract::Interfaces::IPriorityElement& data;
        };
    }
}