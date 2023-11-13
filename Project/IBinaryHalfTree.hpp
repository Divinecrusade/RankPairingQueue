#pragma once

#include "IPriorityElement.hpp"
#include "IList.hpp"

namespace PriorityQueue
{
    namespace BinaryHalfTree
    {
        template<class ElType, std::equality_comparable Type>
        __interface IBinaryHalfTree
        {
        public:
            
            virtual void insert(IPriorityElement const* element) = 0;
            virtual unsigned get_rank() const = 0;
            virtual void merge(IBinaryHalfTree* other_tree) = 0;
            virtual IBinaryHalfTree* get_left() const = 0;
            virtual IBinaryHalfTree* get_right() const = 0;
            virtual IBinaryHalfTree* extract() = 0;
            virtual bool is_root() const = 0;
            virtual IList* get_data() const = 0;
        };
    }
}