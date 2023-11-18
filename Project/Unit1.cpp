#include "RankPairingQueue.hpp"
#include "Detail.hpp"

#include <iostream>

int main()
{
    using namespace PriorityQueue;

    Detail details1[]{ {0, 0}, {-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}, {-8, 8} , {-9, 9} , {-10, 10} };
    RankPairingQueue rpq{};
    
    rpq.insert(details1[5U]);
    rpq.insert(details1[1U]);
    rpq.insert(details1[4U]);
    rpq.insert(details1[8U]);
    rpq.insert(details1[9U]);




    std::cout << rpq.minimum().get_priority() << std::endl;
    //rpq.extract_min();
    rpq.decrease_key(details1[8U], 0U);
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;
    rpq.extract_min();
    std::cout << rpq.minimum().get_priority() << std::endl;


    return EXIT_SUCCESS;
}