#ifndef _DICEROLL_DICE_EXPR_HPP
#define _DICEROLL_DICE_EXPR_HPP

#include <memory>
#include <stdexcept>

namespace Diceroll {
    class ExpressionNode;
    
    template<class T>
    using is_dice_expr_t = typename std::is_base_of<ExpressionNode, T>;
    
    
    class DiceExpr {
    public:
        template<typename T>
        DiceExpr(T&& expr,
                 typename std::enable_if_t<is_dice_expr_t<T>::value>* = 0);
        DiceExpr(std::shared_ptr<ExpressionNode> node);
        DiceExpr(const DiceExpr &) = default;
        DiceExpr(DiceExpr&&) = default;
        DiceExpr& operator=(const DiceExpr&) = delete;
        const ExpressionNode& operator*() const;
        const ExpressionNode* operator->() const;
        const DiceExpr operator+(const DiceExpr& other);
    private:
        std::shared_ptr<ExpressionNode> ptr;
    };
    
    template<typename T>
    DiceExpr::DiceExpr(T&& expr, typename std::enable_if_t<is_dice_expr_t<T>::value>*) :
    DiceExpr(std::make_shared<T>(expr)) {}
    
}
#endif
