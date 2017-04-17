#ifndef _DICEROLL_DISTRIBUTION_HPP
#define _DICEROLL_DISTRIBUTION_HPP

#include <map>

namespace Diceroll {
    /**
     This class models a probabilty distribution.
     */
    class Distribution {
        using ValueType = long long;
        using ProbType = long double;
        using MapType = std::map<ValueType, ProbType>;
    public:
        static Distribution uniformRange(ValueType start, ValueType end);
        
        /**
         Obtain the probability of a given value i.
         If i is not in the map, 0.0 will be returned.
         */
        ProbType operator[](ValueType i) const;
        
        /**
         Obtain a reference to the underlying mapping type.
         */
        inline const MapType& getMap() const { return map; }
        
        /**
         Obtain the average value of this distribution.
         */
        double average() const;
        
        int max() const noexcept;
        
        int min() const noexcept;
        
        Distribution convolveAdd(const Distribution& o) const noexcept;
        
        template<typename BinaryOperator>
        Distribution convolve(const Distribution& other,
                              BinaryOperator op) const noexcept(noexcept(op));
        
    private:
        MapType map;
    };
    
    template<typename BinaryOperator>
    Distribution Distribution::convolve(const Distribution& other,
                                        BinaryOperator op) const noexcept(noexcept(op)) {
        
        Distribution ret;
        auto& m = ret.map;
        auto mergeIn = [&](int val, double prob) {
            if(m.find(val) == m.end()) {
                m.emplace(std::make_pair(val, 0));
            }
            auto loc = m.find(val);
            loc->second += prob;
        };
        for(int i = min(); i <= max(); ++i) {
            for(int k = other.min(); k <= other.max(); k++) {
                auto ret = op(i, k);
                mergeIn(op(i, k), (*this)[i] * other[k]);
            }
        }
        return ret;
    }
}
#endif
