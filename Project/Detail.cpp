#include "Detail.hpp"
#include <cassert>

PriorityQueue::Detail::Detail(int id, unsigned priority) : id{ id }, priority{ priority }
{ }

PriorityQueue::Detail::Detail(Detail const& some_detail)
:
id{ some_detail.id },
priority{ some_detail.priority }
{ }

unsigned PriorityQueue::Detail::get_priority() const
{
    return priority;
}

void PriorityQueue::Detail::set_priority(unsigned new_priority)
{
    assert(new_priority < priority);

    priority = new_priority;
}

int PriorityQueue::Detail::get_id() const
{
    return id;
}
