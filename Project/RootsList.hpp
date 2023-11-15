#pragma once

#include "RBHalfTreeRoot.hpp"

namespace PriorityQueue
{
    namespace Auxiliry
    {
        class RootsList
        {
        private:

            struct Node
            {
                RBHalfTreeRoot* root;
                Node* next { nullptr };
            };

        public:
            
            RootsList() = default;
            RootsList(RootsList const&) = delete;
            RootsList(RootsList&&) = delete;

            RootsList& operator=(RootsList const&) = delete;
            RootsList& operator=(RootsList&&) = delete;

            ~RootsList();

            void set_first(Detail const& some_detail) noexcept;
            void set_second(Detail const& some_detail) noexcept;

            RBHalfTreeRoot* get_first() noexcept;
            RBHalfTreeRoot* get_second() noexcept;

            void unite_roots_with_same_ranks();

        private:
            
            void set_first(Node* new_node) noexcept;
            void set_second(Node* new_node) noexcept;
            void unite(Node* prev1, Node* node1, Node* node2, Node* prev2);

            Node* first{ nullptr };
        };
    }
}