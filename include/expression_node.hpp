#ifndef _DICEROLL_EXPRESSION_NODE_HPP
#define _DICEROLL_EXPRESSION_NODE_HPP

#include <memory>
#include "distribution.hpp"
#include "dice_expr.hpp"

namespace Diceroll {
    class ExpressionNode {
    public:
        virtual int value() const = 0;
        virtual DiceExpr reroll() const = 0;
        virtual const Distribution& distribution() const = 0;
    };
};
#endif
