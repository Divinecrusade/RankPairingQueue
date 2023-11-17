#include "Detail.hpp"
#include <cassert>

PriorityQueue::Detail::Detail(int id, unsigned priority) : id{ id }, priority{ priority }
{ }

unsigned PriorityQueue::Detail::get_priority() const
{
    return priority;
}

void PriorityQueue::Detail::set_priority(int new_priority)
{
    assert(new_priority < priority);

    priority = new_priority;
}

int PriorityQueue::Detail::get_id() const
{
    return id;
}
