#include "add_node.hpp"
#include <iostream>

namespace Diceroll {
    AddNode::AddNode(const DiceExpr& _lhs,
                     const DiceExpr& _rhs) :
        lhs(_lhs), rhs(_rhs) {}
    
    
    const Distribution& AddNode::distribution() const {
        if(dist) {
            return *dist;
        }
        else {
            dist = lhs->distribution().convolveAdd(rhs->distribution());
            return *dist;
        }
    }
    
    
    DiceExpr AddNode::reroll() const {
        return AddNode(lhs->reroll(), rhs->reroll());
    }
}
