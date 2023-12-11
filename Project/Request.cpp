#include "Request.hpp"
#include <cassert>

PriorityQueue::Request::Request(int id, unsigned priority) : id{ id }, priority{ priority }
{ }

PriorityQueue::Request::Request(Request const& some_detail)
:
id{ some_detail.id },
priority{ some_detail.priority }
{ }

unsigned PriorityQueue::Request::get_priority() const
{
    return priority;
}

void PriorityQueue::Request::set_priority(unsigned new_priority)
{
    assert(new_priority < priority);

    priority = new_priority;
}

int PriorityQueue::Request::get_id() const
{
    return id;
}
