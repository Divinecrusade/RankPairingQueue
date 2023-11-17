#pragma once

#include "IRankedRootsList.hpp"

namespace PriorityQueue
{
    namespace Auxiliry
    {
        class RankedRootsList : public Abstract::Interfaces::IRankedRootsList
        {
        private:

            struct Node
            {
                Abstract::MeldableRankedBinaryTree* root;
                Node* next{ nullptr };
            };

        public:
            
            RankedRootsList() = default;
            RankedRootsList(RankedRootsList const&) = delete;
            RankedRootsList(RankedRootsList&&) = delete;

            RankedRootsList& operator=(RankedRootsList const&) = delete;
            RankedRootsList& operator=(RankedRootsList&&) = delete;

            virtual ~RankedRootsList();

            virtual void set_first(Abstract::MeldableRankedBinaryTree* root) override;
            virtual void set_second(Abstract::MeldableRankedBinaryTree* root) override;

            virtual Abstract::MeldableRankedBinaryTree const& get_first() const noexcept override;
            virtual Abstract::MeldableRankedBinaryTree* remove_first() noexcept override;

            virtual bool is_empty() const noexcept override;

            virtual void unite_trees_with_same_rank() override;

        protected:

            void unite(Node* prev1, Node* node1, Node* prev2, Node* node2);

        private:

            Node* first{ nullptr };
        };
    }
}