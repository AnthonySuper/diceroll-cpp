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
        
        virtual std::shared_ptr<ExpressionNode> reroll() const override;
        
    private:
        const int type;
        const int _value;
    };
}
#endif
