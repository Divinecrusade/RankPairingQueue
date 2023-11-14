#pragma once

class Detail
{
public:

    Detail() = delete;
    Detail(int id, unsigned priority);
    Detail(Detail const& other_detail);
    Detail(Detail&&) = delete;

    Detail& operator=(Detail const&) = delete;
    Detail& operator=(Detail&&) = delete;

    ~Detail() = default;

    unsigned get_priority() const noexcept;
    void set_priority(unsigned new_priority) noexcept;
    int get_id() const noexcept;

private:
    
    int id;
    unsigned priority;
};