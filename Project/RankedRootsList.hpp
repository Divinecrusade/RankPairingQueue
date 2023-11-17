#pragma once

#include "IRankedRootsList.hpp"

namespace PriorityQueue
{
    namespace Auxiliry
    {
        class RankedRootsList : public Interfaces::IRankedRootsList
        {
        private:

            struct Node
            {
                Interfaces::IRankedTree* root;
                Node* next{ nullptr };
            };

        public:
            
            RankedRootsList() = default;
            RankedRootsList(RankedRootsList const&) = delete;
            RankedRootsList(RankedRootsList&&) = delete;

            RankedRootsList& operator=(RankedRootsList const&) = delete;
            RankedRootsList& operator=(RankedRootsList&&) = delete;

            virtual ~RankedRootsList();

            virtual void set_first(Interfaces::IRankedTree* root) override;
            virtual void set_second(Interfaces::IRankedTree* root) override;

            virtual Interfaces::IRankedTree const& get_first() const noexcept override;
            virtual Interfaces::IRankedTree* remove_first() noexcept override;

            virtual bool is_empty() const noexcept override;

            virtual void unite_trees_with_same_rank() override;

        protected:

            void unite(Node* prev1, Node* node1, Node* prev2, Node* node2);

        private:

            Node* first{ nullptr };
        };
    }
}