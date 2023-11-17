#pragma once

#include "IRankedBinaryTree.hpp"
#include "IPriorityElement.hpp"

namespace PriorityQueue
{
    namespace Auxiliry
    {
        class RankedHalfBinaryTree : public Interfaces::IRankedBinaryTree
        {
        public:

            RankedHalfBinaryTree() = delete;
            RankedHalfBinaryTree(Interfaces::IPriorityElement& data);
            RankedHalfBinaryTree(RankedHalfBinaryTree&&);

            RankedHalfBinaryTree& operator=(RankedHalfBinaryTree const&) = delete;
            RankedHalfBinaryTree& operator=(RankedHalfBinaryTree&&) = delete;

            virtual ~RankedHalfBinaryTree();

            virtual void meld(IRankedBinaryTree& another_root) override;

            virtual unsigned get_rank() const noexcept override;
            virtual void update_rank() noexcept override;

            virtual Interfaces::IPriorityElement const& get_data() const noexcept override;
            virtual Interfaces::IPriorityElement& get_data() noexcept override;

            virtual Interfaces::IRankedRootsList& remove() override;

            virtual bool is_root() const noexcept override;

        private:

            RankedHalfBinaryTree*& get_parent_ptr_on_me() noexcept;

        private:
            
            RankedHalfBinaryTree* parent{ nullptr };
            RankedHalfBinaryTree* left{ nullptr };
            RankedHalfBinaryTree* right{ nullptr };

            Interfaces::IPriorityElement& const data;
            unsigned rank{ 0U };
        };
    }
}