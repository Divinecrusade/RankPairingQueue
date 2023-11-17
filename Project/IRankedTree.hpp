#pragma once

#include "IPriorityElement.hpp"

namespace PriorityQueue
{
    namespace Interfaces
    {
        __interface IRankedTree
        {
            virtual unsigned get_rank() const noexcept = 0;

            virtual IPriorityElement const& get_data() const noexcept = 0;
            virtual IPriorityElement& get_data() noexcept = 0;

            virtual void meld(IRankedTree& tree) = 0;
        };
    }
}