#pragma once

#include "IRankedBinaryTree.hpp"


namespace PriorityQueue
{
    namespace Interfaces
    {
        __interface IRankedRootsList
        {
        public:

            virtual void set_first(Interfaces::IRankedBinaryTree const& root) = 0;
            virtual void set_second(Interfaces::IRankedBinaryTree const& root) = 0;

            virtual Interfaces::IRankedBinaryTree const& get_first() const noexcept = 0;
            virtual void remove_first() = 0;

            virtual bool is_empty() const noexcept;

            virtual void unite_trees_with_same_ranks() = 0;
        };
    }
}