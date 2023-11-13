#pragma once

#include "IList.hpp"

namespace PriorityQueue
{
    namespace Auxiliry
    {
        template<class ElType>
        class ForwardList : public Interfaces::IList<ElType>
        {
        private:

            template<class ElType>
            struct Node
            {
                ElType& element;
                Node* next{ nullptr };
            };

        public:

            virtual void insert(ElType const& element, size_t pos = 0U) = 0;
            virtual ElType& get(size_t pos) = 0;
            virtual ElType& remove(size_t pos) = 0;

        private:

            Node* first{ nullptr };
            Node* last { nullptr };
        };
    }
}