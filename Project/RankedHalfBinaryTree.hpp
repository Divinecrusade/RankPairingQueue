#pragma once

#include "MeldableRankedBinaryTree.hpp"

namespace PriorityQueue
{
    namespace Auxiliry
    {
        class RankedHalfBinaryTree : public Abstract::MeldableRankedBinaryTree
        {
        public:

            RankedHalfBinaryTree() = delete;
            RankedHalfBinaryTree(Abstract::Interfaces::IPriorityElement& data);
            RankedHalfBinaryTree(RankedHalfBinaryTree&&) = delete;

            RankedHalfBinaryTree& operator=(RankedHalfBinaryTree const&) = delete;
            RankedHalfBinaryTree& operator=(RankedHalfBinaryTree&&) = delete;

            virtual ~RankedHalfBinaryTree() = default;

            virtual void meld(MeldableRankedBinaryTree* root) override;

            virtual MeldableRankedBinaryTree* find(Abstract::Interfaces::IPriorityElement const& data) override;

            virtual void attach(MeldableRankedBinaryTree* node) override;
            virtual void replace(MeldableRankedBinaryTree* node1, MeldableRankedBinaryTree* node2) override;
        };
    }
}