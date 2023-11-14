#pragma once

#include "Detail.hpp"

#include <stdexcept>
#include <string>


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

            virtual ~ForwardList()
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

            virtual void insert(int id, unsigned priority, size_t pos = 0U)
            {
                Node* new_node{ new Node{ Detail{ id, priority } } };
                Node* prev{ nullptr };
                Node* cur{ first };

                while (cur != nullptr && pos != 0U)
                {
                    prev = cur;
                    cur = cur->next;
                    --pos;
                }
                if (pos != 0U && cur == nullptr) throw OutOfRange{ "List is shorter than reqiured index" };

                if (first == nullptr)
                {
                    first = last = new_node;
                }
                else
                {
                    new_node->next = prev->next;
                    prev->next = new_node;

                    if (last == cur) last = new_node;
                }
            }
            virtual void insert_front(int id, unsigned priority)
            {
                Node* new_node{ new Node{ Detail{id, priority} } };
                
                if (first == nullptr) first = last = new_node;
                else
                {
                    new_node->next = first;
                    first = new_node;
                }
            }
            virtual void insert_back(int id, unsigned priority)
            {
                Node* new_node{ new Node{ Detail{id, priority} } };

                if (last == nullptr) last = first = new_node;
                else
                {
                    last->next = new_node;
                    last = new_node;
                }
            }
            virtual Detail& get(size_t pos)
            {
                Node* cur{ first };

                while (cur != nullptr && pos != 0U)
                {
                    cur = cur->next;
                    --pos;
                }
                if (pos != 0U && cur == nullptr) throw OutOfRange{ "List is shorter than reqiured index" };

                return cur->element;
            }
            virtual void remove(size_t pos)
            {
                Node* prev{ nullptr };
                Node* cur{ first };

                while (cur != nullptr && pos != 0U)
                {
                    prev = cur;
                    cur = cur->next;
                    --pos;
                }
                if (pos != 0U && cur == nullptr) throw OutOfRange{ "List is shorter than reqiured index" };

                if (first == last)
                {
                    first = last = nullptr;
                }
                else if (cur == first)
                {
                    first = first->next;
                }
                else
                {
                    prev->next = cur->next;

                    cur->next = nullptr;

                    if (cur == last)
                    {
                        last = prev;
                    }
                }

                delete cur;
            }

        private:

            Node* first{ nullptr };
            Node* last { nullptr };
        };
    }
}