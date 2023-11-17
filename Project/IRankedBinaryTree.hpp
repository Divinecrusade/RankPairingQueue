#pragma once

#include "IPriorityElement.hpp"
#include "IRankedRootsList.hpp"

namespace PriorityQueue
{
    namespace Interfaces
    {
        __interface IRankedBinaryTree
        {
        public:

            virtual void meld(IRankedBinaryTree& another_root) = 0;

            virtual unsigned get_rank() const noexcept = 0;
            virtual void update_rank() noexcept = 0;

            virtual IPriorityElement const& get_minimum() const noexcept = 0;

            virtual IRankedRootsList& remove() = 0;

            virtual bool is_empty() const noexcept = 0;
        };
    }
}