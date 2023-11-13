#pragma once

#include <concepts>


namespace PriorityQueue
{
    namespace Interfaces
    {
        template<std::equality_comparable Type>
        __interface IPriorityElement
        {
        public:

            virtual unsigned get_priority() const = 0;
            virtual void set_priority(int new_priority) = 0;
            virtual Type const& get_data() const = 0;
        };
    }
}   