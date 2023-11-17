#pragma once

#include "IRankedTree.hpp"
#include "IRankedRootsList.hpp"

namespace PriorityQueue
{
    namespace Abstract
    {
        class MeldedRankedTree : public Interfaces::IRankedTree
        {
        public:

            virtual unsigned get_rank() const noexcept override;

            virtual Interfaces::IPriorityElement const& get_data() const noexcept override;
            virtual Interfaces::IPriorityElement& get_data() noexcept override;

            virtual void meld(MeldedRankedTree& tree) = 0;
            
            virtual Interfaces::IRankedRootsList* remove() = 0;

            virtual bool is_root() const noexcept = 0;

        protected:
            

        private:

            
            unsigned rank{ 0U };
            
        };
    }
}