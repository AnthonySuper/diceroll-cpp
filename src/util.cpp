#include "util.hpp"

namespace Diceroll {
    DiceExpr roll(int num, int type) {
        if(num == 0) {
            return IntegerNode(0);
        }
        DiceExpr exp = RollNode(type);
        for(int i = 1; i < num; ++i) {
            exp = (exp + RollNode(type));
        }
        return exp;
    }
    
    namespace Literals {
        DiceExpr operator ""_d20(unsigned long long i) {
            return roll(i, 20);
        }
        
        DiceExpr operator ""_d12(unsigned long long i) {
            return roll(i, 12);
        }
        
        DiceExpr operator ""_d10(unsigned long long i) {
            return roll(i, 10);
        }
        
        DiceExpr operator ""_d8(unsigned long long i) {
            return roll(i, 8);
        }
        
        DiceExpr operator ""_d6(unsigned long long i) {
            return roll(i, 6);
        }
        
        DiceExpr operator ""_d4(unsigned long long i) {
            return roll(i, 4);
        }
    }
}
