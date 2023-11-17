#include "RankPairingQueue.hpp"
#include "Detail.hpp"

#include <iostream>

int main()
{
    using namespace PriorityQueue;

    Detail details1[]{ {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8} , {0, 9} , {0, 10} };
    RankPairingQueue rpq{};
    rpq.insert(details1[1U]);
    rpq.insert(details1[2U]);
    rpq.insert(details1[0U]);
    rpq.insert(details1[5U]);
    rpq.insert(details1[7U]);
    rpq.insert(details1[3U]);
    rpq.insert(details1[6U]);
    rpq.insert(details1[8U]);
    rpq.insert(details1[9U]);
    rpq.insert(details1[10U]);
    rpq.insert(details1[4U]);




    std::cout << rpq.minimum().get_priority() << std::endl; // 0
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 1
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 2
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 3
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 4
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 5
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 6
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 7
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 8
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 9
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl; // 10


    return EXIT_SUCCESS;
}