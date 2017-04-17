#ifndef _DICEROLL_ROLL_NODE_HPP
#define _DICEROLL_ROLL_NODE_HPP

#include <expression_node.hpp>

namespace Diceroll {
    class RollNode : public ExpressionNode {
    public:
        RollNode(ResultNum type, ResultNum value);
        RollNode(ResultNum type);
        
        static int rollDice(int type) noexcept;
        
        virtual ResultNum value() const override;
        
        virtual DiceExpr reroll() const override;
        
        virtual const Distribution& distribution() const override;
        
    private:
        const long long type;
        const long long _value;
        const Distribution dist;
    };
}
#endif
