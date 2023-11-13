#pragma once

#include "IBinaryHalfTree.hpp"

namespace PriorityQueue
{
    namespace BinaryHalfTree
    {
        template<class ElType, std::equality_comparable Type>
        class BinaryHalfTree : public IBinaryHalfTree
        {
        public:

            BinaryHalfTree() = delete;
            BinaryHalfTree(IPriorityElement const*);
            BinaryHalfTree(BinaryHalfTree const&) = delete;
            BinaryHalfTree(BinaryHalfTree&&) = delete;

            BinaryHalfTree& operator=(BinaryHalfTree const&) = delete;
            BinaryHalfTree& operator=(BinaryHalfTree&&) = delete;

            virtual ~BinaryHalfTree();


            virtual void insert(IPriorityElement const* element) = 0;
            virtual unsigned get_rank() const = 0;
            virtual void merge(IBinaryHalfTree* other_tree) = 0;
            virtual IBinaryHalfTree* get_left() const = 0;
            virtual IBinaryHalfTree* get_right() const = 0;
            virtual IBinaryHalfTree* extract() = 0;
            virtual bool is_root() const = 0;
            virtual IList* get_data() const = 0;

        private:

            BinaryHalfTree* left{ nullptr };
            BinaryHalfTree* right{ nullptr };
            BinaryHalfTree* parent{ nullptr };
            unsigned rank;
        };
    }
}