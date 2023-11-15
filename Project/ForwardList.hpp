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

            ~ForwardList();

            void insert(Detail const& some_detail, size_t pos = 0U);
            void insert_front(Detail const& some_detail);
            void insert_back(Detail const& some_detail);
            Detail& get(size_t pos);
            void remove(size_t pos);
            bool is_empty() const noexcept;

        private:

            Node* first{ nullptr };
            Node* last { nullptr };
        };
    }
}