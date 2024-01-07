#pragma once

#include <concepts>


namespace PriorityQueue
{
    namespace Abstract
    {
        namespace Interfaces
        {
            __interface IPriorityElement
            {
            public:

                virtual unsigned get_priority() const = 0;
                virtual void set_priority(unsigned new_priority) = 0;
                virtual int get_id() const = 0;
            };
        }
    }
}   