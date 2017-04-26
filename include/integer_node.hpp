#ifndef _INTEGER_NODE_HPP
#define _INTEGER_NODE_HPP
#include "expression_node.hpp"

namespace Diceroll {
    class IntegerNode : public ExpressionNode {
    public:
        inline IntegerNode(int i) : num(i),
        dist(Distribution::uniformRange(i, i)){}
        
        inline virtual ResultNum value() const override {
            return num;
        }
        
        inline virtual const Distribution& distribution() const override {
            
            return dist;
        }
        
        inline virtual DiceExpr reroll() const override {
            return IntegerNode(num);
        }
        
    private:
        const ResultNum num;
        const Distribution dist;
        
    };
}
#endif
