#include "ForwardList.hpp"

void PriorityQueue::Auxiliry::ForwardList::insert(Detail const& some_detail, size_t pos)
{
    Node* new_node{ new Node{ some_detail } };
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

void PriorityQueue::Auxiliry::ForwardList::insert_front(Detail const& some_detail)
{
    Node* new_node{ new Node{ some_detail } };

    if (first == nullptr) first = last = new_node;
    else
    {
        new_node->next = first;
        first = new_node;
    }
}

void PriorityQueue::Auxiliry::ForwardList::insert_back(Detail const& some_detail)
{
    Node* new_node{ new Node{ some_detail } };

    if (last == nullptr) last = first = new_node;
    else
    {
        last->next = new_node;
        last = new_node;
    }
}

Detail& PriorityQueue::Auxiliry::ForwardList::get(size_t pos)
{
    assert(first);

    Node* cur{ first };

    while (cur != nullptr && pos != 0U)
    {
        cur = cur->next;
        --pos;
    }
    if (pos != 0U && cur == nullptr) throw OutOfRange{ "List is shorter than reqiured index" };

    return cur->element;
}

void PriorityQueue::Auxiliry::ForwardList::remove(size_t pos)
{
    assert(first);

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

bool PriorityQueue::Auxiliry::ForwardList::is_empty() const noexcept
{
    return first == nullptr;
}
