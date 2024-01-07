#pragma once


namespace PriorityQueue
{
    namespace Abstract
    {
        class MeldableRankedBinaryTree;

        namespace Interfaces
        {
            __interface IPriorityElement;

            __interface IRankedRootsList
            {
            public:

                virtual void set_first(MeldableRankedBinaryTree* root) = 0;
                virtual void set_second(MeldableRankedBinaryTree* root) = 0;

                virtual MeldableRankedBinaryTree const& get_first() const noexcept = 0;
                virtual MeldableRankedBinaryTree* remove_first() noexcept = 0;

                virtual bool is_empty() const noexcept;

                virtual void unite_trees_with_same_rank() = 0;

                virtual MeldableRankedBinaryTree* extract_subtree(IPriorityElement const& element) = 0;
            };
        }
    }
}