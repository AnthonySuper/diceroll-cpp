#ifndef _DICEROLL_ADD_NODE_CPP
#define _DICEROLL_ADD_NODE_CPP

#include "expression_node.hpp"
#include "dice_expr.hpp"
#include <memory>


#include <experimental/optional>


namespace Diceroll {
    class AddNode : public ExpressionNode {
        using OptionalDistribution = std::experimental::optional<Distribution>;
        
    public:
        AddNode(const DiceExpr& lhs,
                const DiceExpr& rhs);
        
        virtual DiceExpr reroll() const override;
        
        virtual int value() const override {
            return (lhs->value() + rhs->value());
        }
        
        virtual const Distribution& distribution() const override;
        
        
    private:
        DiceExpr lhs;
        DiceExpr rhs;
        mutable OptionalDistribution dist;
    };
}

#endif
