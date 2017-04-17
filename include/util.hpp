#ifndef _DICEROLL_UTIL_HPP
#define _DICEROLL_UTIL_HPP

#include "dice_expr.hpp"
#include "roll_node.hpp"
#include "add_node.hpp"
#include "integer_node.hpp"

namespace Diceroll {
    
    /**
     Roll a number of dice of the specified type.
     roll(2, 20) is equivalent to rolling 2d20.
     */
    DiceExpr roll(int num, int type);
    
    namespace Literals {
        DiceExpr operator ""_d20(unsigned long long i);
        DiceExpr operator ""_d12(unsigned long long i);
        DiceExpr operator ""_d10(unsigned long long i);
        DiceExpr operator ""_d8(unsigned long long i);
        DiceExpr operator ""_d6(unsigned long long i);
        DiceExpr operator ""_d4(unsigned long long i);
        
    }
}
#endif
