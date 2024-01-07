#pragma once

#include "IPriorityElement.hpp"
#include "IRankedRootsList.hpp"

namespace PriorityQueue
{
    namespace Abstract
    {
        namespace Interfaces
        {
            __interface IRankedTree
            {
            public:

                virtual unsigned get_rank() const noexcept = 0;

                virtual IPriorityElement const& get_data() const noexcept = 0;
                virtual IPriorityElement& get_data() noexcept = 0;
            };
        }
    }
}