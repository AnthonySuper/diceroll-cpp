#ifndef _DICEROLL_EXPRESSION_NODE_HPP
#define _DICEROLL_EXPRESSION_NODE_HPP

#include <memory>

namespace Diceroll {
    class ExpressionNode {
        public:
            virtual int value() const = 0;
            virtual std::shared_ptr<ExpressionNode> reroll() const = 0;
    };
};
#endif
