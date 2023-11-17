#pragma once

#include "IPriorityElement.hpp"

namespace PriorityQueue
{
    namespace Interfaces
    {
        __interface IPriorityQueue
        {
        public:

            virtual void insert(IPriorityElement& element) = 0;
            virtual IPriorityElement const& minimum() const = 0;
            virtual void extract_min() = 0;
            //virtual void decrease_key(Type const& data, unsigned priority) = 0;
        };
    }
}
