#ifndef _DICEROLL_ROLL_NODE_HPP
#define _DICEROLL_ROLL_NODE_HPP

#include <expression_node.hpp>

namespace Diceroll {
    class RollNode : public ExpressionNode {
    public:
        RollNode(int type, int value);
        RollNode(int type);
        
        static int rollDice(int type) noexcept;
        
        virtual int value() const override;
        
        virtual DiceExpr reroll() const override;
        
        virtual const Distribution& distribution() const override;
        
    private:
        const int type;
        const int _value;
        const Distribution dist;
    };
}
#endif
