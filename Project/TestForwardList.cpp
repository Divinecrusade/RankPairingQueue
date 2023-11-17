#include <iostream>
#include "ForwardList.hpp"

int main()
{
    using namespace PriorityQueue::Auxiliry;
    
    ForwardList<int> list{};

    constexpr int n{ 5 };
    for (int i{ 0 }; i < n; ++i)
    {
        list.insert_front(i);
        list.insert_back(i + n);
    }

    for (int i{ 0 }; i != 2 * n; ++i)
    {
        std::cout << list.get(i) << ' ';
    }
    std::cout << std::endl;

    list.remove(2);

    for (int i{ 0 }; i != 2 * n - 1; ++i)
    {
        std::cout << list.get(i) << ' ';
    }
    std::cout << std::endl;

    list.remove(0);

    for (int i{ 0 }; i != 2 * n - 2; ++i)
    {
        std::cout << list.get(i) << ' ';
    }
    std::cout << std::endl;

    list.remove(7U);

    for (int i{ 0 }; i != 2 * n - 3; ++i)
    {
        std::cout << list.get(i) << ' ';
    }
    std::cout << std::endl;


    return EXIT_SUCCESS;
}