#pragma once

#include "IRankedRootsList.hpp"

namespace PriorityQueue
{
    namespace Interfaces
    {
        __interface IRankedBinaryTree
        {
        public:

            virtual IRankedRootsList& remove() = 0;

            virtual bool is_root() const noexcept = 0;

            //virtual void bind_left(IRankedBinaryTree& another_root) = 0;
            //virtual void bind_right(IRankedBinaryTree& another_root) = 0;
        };
    }
}