#include "RankPairingQueue.hpp"
#include <iostream>

int main()
{
    using namespace PriorityQueue;
    using namespace Auxiliry;

    Detail details1[] { {0, 0}, {0, 1}, {0, 2}, {0, 3} };
    RankPairingQueue rpq{};
    rpq.insert(details1[1U]);
    rpq.insert(details1[2U]);
    rpq.insert(details1[3U]);
    rpq.insert(details1[0U]);


    std::cout << rpq.minimum().get_priority();

    return EXIT_SUCCESS;
}