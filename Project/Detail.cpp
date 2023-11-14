#include "Detail.hpp"

Detail::Detail(int id, unsigned priority) : id{ id }, priority{ priority }
{ }

Detail::Detail(Detail const& other_detail) : id{ other_detail.id }, priority{ other_detail.priority }
{ }

unsigned Detail::get_priority() const noexcept
{
    return priority;
}

void Detail::set_priority(unsigned new_priority) noexcept
{
    priority = new_priority;
}

int Detail::get_id() const noexcept
{
    return id;
}
