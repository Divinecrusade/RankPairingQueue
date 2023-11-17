#include "RankedHalfBinaryTree.hpp"
#include <cassert>

PriorityQueue::Auxiliry::RankedHalfBinaryTree::RankedHalfBinaryTree(Abstract::Interfaces::IPriorityElement& data)
:
MeldableRankedBinaryTree{ data }
{ }

void PriorityQueue::Auxiliry::RankedHalfBinaryTree::meld(MeldableRankedBinaryTree* root)
{
    root->bind_right(remove_left_subtree());
    bind_left(root);
}
