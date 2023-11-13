#pragma once

#include <concepts>


namespace PriorityQueue
{
    namespace Interfaces
    {
        template<class ElType, std::equality_comparable Type>
        __interface IList
        {
            virtual void insert(ElType const& element, size_t pos = 0U) = 0;
            virtual ElType& get(size_t pos) = 0;
            virtual ElType& remove(size_t pos) = 0;
            virtual ElType& find(Type key) = 0;
        };
    }
}