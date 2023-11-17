#pragma once

#include <concepts>


namespace PriorityQueue
{
    namespace Interfaces
    {
        __interface IPriorityElement
        {
        public:

            virtual unsigned get_priority() const = 0;
            virtual void set_priority(int new_priority) = 0;
            virtual int get_id() const = 0;
        };
    }
}   