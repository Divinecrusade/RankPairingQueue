#pragma once

#include "IPriorityElement.hpp"

namespace PriorityQueue
{
    class Request : public Abstract::Interfaces::IPriorityElement
    {
    public:
    
        Request(int id, unsigned priority);
        Request(Request const& some_detail);
        Request(Request&&) = default;

        Request& operator=(Request const&) = default;
        Request& operator=(Request&&) = default;

        virtual ~Request() = default;

        virtual unsigned get_priority() const override;
        virtual void set_priority(unsigned new_priority) override;
        virtual int get_id() const override;

    private:

        int const id;
        unsigned priority;
    };
}