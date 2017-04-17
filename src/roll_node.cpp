#include <roll_node.hpp>
#include <random>

namespace Diceroll {
    RollNode::RollNode(ResultNum type) :
        RollNode(type, RollNode::rollDice(type)) {}
    
    RollNode::RollNode(ResultNum type, ResultNum value) :
    type(type),
    _value(value),
    dist(Distribution::uniformRange(1, type)) {
        if(_value > type || _value < 1) {
            throw std::runtime_error("Impossible roll");
        }
    }
    
    int RollNode::rollDice(int type) noexcept {
        std::default_random_engine generator;
        std::uniform_int_distribution<> distribution(1, type);
        return distribution(generator);
    }
    
    ExpressionNode::ResultNum RollNode::value() const {
        return _value;
    }
    
    DiceExpr RollNode::reroll() const {
        return RollNode(type);
    }
    
    const Distribution& RollNode::distribution() const {
        return dist;
    }
    
}
