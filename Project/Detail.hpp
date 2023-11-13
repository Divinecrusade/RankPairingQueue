#pragma once

#include "IPriorityElement.hpp"

template<std::equality_comparable Type>
class Detail : PriorityQueue::Interfaces::IPriorityElement<Type>
{
public:

    Detail() = delete;
    Detail(Type const& id, unsigned priority);
    Detail(Detail const&) = delete;
    Detail(Detail&&) = delete;

    Detail& operator=(Detail const&) = delete;
    Detail& operator=(Detail&&) = delete;

    virtual ~Detail() = default;

    virtual unsigned get_priority() const = 0;
    virtual void set_priority(int new_priority) = 0;
    virtual Type const& get_data() const = 0;

private:
    
    Type id;
    unsigned priority;
};