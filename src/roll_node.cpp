#include <roll_node.hpp>
#include <random>

namespace Diceroll {
    RollNode::RollNode(int type) :
        RollNode(type, RollNode::rollDice(type)) {}
    
    RollNode::RollNode(int type, int value) :
    type(type), _value(value) {
        if(_value > type || _value < 1) {
            throw std::runtime_error("Impossible roll");
        }
    }
    
    int RollNode::rollDice(int type) noexcept {
        std::default_random_engine generator;
        std::uniform_int_distribution<> distribution(1, type);
        return distribution(generator);
    }
    
    int RollNode::value() const {
        return _value;
    }
    
    std::shared_ptr<ExpressionNode> RollNode::reroll() const {
        return std::make_shared<RollNode>(type);
    }
    
}
