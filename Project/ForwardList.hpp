#pragma once

#include "IList.hpp"

namespace PriorityQueue
{
    namespace Auxiliry
    {
        template<class ElType, std::equality_comparable Type>
        class ForwardList : public Interfaces::IList
        {
        private:

            struct Node
            {
                ElType& element;
                Node* next{ nullptr };
            };

        public:

            virtual void insert(ElType const& element, size_t pos = 0U) = 0;
            virtual ElType& get(size_t pos) = 0;
            virtual ElType& remove(size_t pos) = 0;
            virtual ElType& find(Type key) = 0;

        private:

            ForwardList* first{ nullptr };
            ForwardList* last { nullptr };
        };
    }
}