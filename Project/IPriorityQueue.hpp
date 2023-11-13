#pragma once

#include "IPriorityElement.hpp"

namespace PriorityQueue
{
    template<std::equality_comparable Type>
    __interface IPriorityQueue
    {
    public:

        virtual void insert(IPriorityElement<Type> const* element) = 0;
        virtual IPriorityElement<Type> const* minimum() const = 0;
        virtual IPriorityElement<Type>* extract_min() = 0;
        virtual void decrease_key(Type const& data, unsigned priority) = 0;
        virtual void meld(IPriorityQueue* pq) = 0;
    };
}
