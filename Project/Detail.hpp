#pragma once

class Detail
{
public:

    Detail() = delete;
    Detail(int id, unsigned priority);
    Detail(Detail const&) = delete;
    Detail(Detail&&) = delete;

    Detail& operator=(Detail const&) = delete;
    Detail& operator=(Detail&&) = delete;

    virtual ~Detail() = default;

    virtual unsigned get_priority() const;
    virtual void set_priority(unsigned new_priority);
    virtual int get_id() const;

private:
    
    int id;
    unsigned priority;
};