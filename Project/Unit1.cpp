#include "RankPairingQueue.hpp"
#include <iostream>

int main()
{
    using namespace PriorityQueue;
    using namespace Auxiliry;

    Detail details1[] { {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8} , {0, 9} , {0, 10} };
    RankPairingQueue rpq{};
    rpq.insert(details1[4U]);
    rpq.insert(details1[7U]);
    rpq.insert(details1[3U]);
    rpq.insert(details1[5U]);
    rpq.insert(details1[6U]);
    rpq.insert(details1[1U]);
    rpq.insert(details1[8U]);
    rpq.insert(details1[2U]);


    std::cout << rpq.minimum().get_priority() << std::endl;
    //rpq.extract_min();
    //std::cout << rpq.minimum().get_priority() << std::endl;
    //rpq.extract_min();
    /*std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;*/


    return EXIT_SUCCESS;
}