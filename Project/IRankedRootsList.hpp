#pragma once

#include "IRankedTree.hpp"

namespace PriorityQueue
{
    namespace Interfaces
    {
        __interface IRankedRootsList
        {
        public:

            virtual void set_first(Interfaces::IRankedTree* root) = 0;
            virtual void set_second(Interfaces::IRankedTree* root) = 0;

            virtual Interfaces::IRankedTree const& get_first() const noexcept = 0;
            virtual Interfaces::IRankedTree* remove_first() noexcept = 0;

            virtual bool is_empty() const noexcept;

            virtual void unite_trees_with_same_rank() = 0;
        };
    }
}