#pragma once

#include "IList.hpp"
#include <stdexcept>
#include <string>

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
                ElType element;
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
                Node<ElType>* tmp{ first->next };
                while (first != last)
                {
                    delete first;
                    first = tmp;
                    tmp = first->next;
                }
                delete first;
                first = last = nullptr;
            }

            virtual void insert(ElType const& element, size_t pos = 0U)
            {
                Node<ElType>* new_node{ new Node{element} };
                Node<ElType>* prev{ nullptr };
                Node<ElType>* cur{ first };

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
            virtual void insert_front(ElType const& element)
            {
                Node<ElType>* new_node{ new Node{element} };
                
                if (first == nullptr) first = last = new_node;
                else
                {
                    new_node->next = first;
                    first = new_node;
                }
            }
            virtual void insert_back(ElType const& element)
            {
                Node<ElType>* new_node{ new Node<ElType>{element, nullptr} };

                if (last == nullptr) last = first = new_node;
                else
                {
                    last->next = new_node;
                    last = new_node;
                }
            }
            virtual ElType& get(size_t pos)
            {
                Node<ElType>* cur{ first };

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
                Node<ElType>* prev{ nullptr };
                Node<ElType>* cur{ first };

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

            Node<ElType>* first{ nullptr };
            Node<ElType>* last { nullptr };
        };
    }
}