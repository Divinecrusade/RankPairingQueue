#pragma once

#include "IPriorityElement.hpp"

namespace PriorityQueue
{
    class Detail : public Interfaces::IPriorityElement
    {
    public:
    
        Detail(int id, unsigned priority);
        Detail(Detail const& some_detail);
        Detail(Detail&&) = delete;

        Detail& operator=(Detail const&) = delete;
        Detail& operator=(Detail&&) = delete;

        virtual ~Detail() = default;

        virtual unsigned get_priority() const override;
        virtual void set_priority(int new_priority) override;
        virtual int get_id() const override;

    private:

        int const id;
        unsigned priority;
    };
}