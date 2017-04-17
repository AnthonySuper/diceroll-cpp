#include "dice_expr.hpp"
#include "add_node.hpp"

namespace Diceroll {
    
    DiceExpr::DiceExpr(std::shared_ptr<ExpressionNode> node)
    : ptr(node) {
        if(ptr == nullptr) {
            throw std::runtime_error("Cannot have a null expression");
        }
    }
    const ExpressionNode& DiceExpr::operator*() const {
        return *ptr;
    }
    
    const ExpressionNode* DiceExpr::operator->() const {
        return ptr.get();
    }
    
    const DiceExpr DiceExpr::operator+(const DiceExpr& other) {
        return AddNode(*this, other);
    }
}
