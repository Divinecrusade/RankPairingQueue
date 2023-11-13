#pragma once

#include <concepts>


namespace PriorityQueue
{
    namespace Interfaces
    {
        template<class ElType>
        __interface IList
        {
            virtual void insert(ElType const& element, size_t pos = 0U) = 0;
            virtual ElType& get(size_t pos) = 0;
            virtual ElType& remove(size_t pos) = 0;
        };
    }
}