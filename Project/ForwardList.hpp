#pragma once

#include "Detail.hpp"

#include <stdexcept>
#include <string>
#include <cassert>


namespace PriorityQueue
{
    namespace Auxiliry
    {
        class ForwardList
        {
        private:

            struct Node
            {
                Detail element;
                Node* next{ nullptr };
            };

        public:

            class OutOfRange : public std::runtime_error
            {
            public:

                OutOfRange(std::string msg) : std::runtime_error{ msg } { }
            };

        public:

            ForwardList() = default;
            ForwardList(ForwardList const&) = delete;
            ForwardList(ForwardList&&) = delete;

            ForwardList& operator=(ForwardList const&) = delete;
            ForwardList& operator=(ForwardList&&) = delete;

            ~ForwardList()
            {
                Node* tmp{ first->next };
                while (first != last)
                {
                    delete first;
                    first = tmp;
                    tmp = first->next;
                }
                delete first;
                first = last = nullptr;
            }

            void insert(Detail const& some_detail, size_t pos = 0U);
            void insert_front(Detail const& some_detail);
            void insert_back(Detail const& some_detail);
            Detail& get(size_t pos);
            void remove(size_t pos);

        private:

            Node* first{ nullptr };
            Node* last { nullptr };
        };
    }
}