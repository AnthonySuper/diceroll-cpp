#include "distribution.hpp"
#include <numeric>

namespace Diceroll {
    double Distribution::operator[](int i) const {
        auto it = map.find(i);
        if(it == map.end()) {
            return 0.0;
        }
        else {
            return (*it).second;
        }
    }
    
    double Distribution::average() const {
        return std::accumulate(map.begin(),
                               map.end(),
                               0.0,
                               [=](double init,
                                   std::pair<const int, double> pair) {
            return init + (pair.first * pair.second);
        });
    }
    
    
    Distribution Distribution::uniformRange(int start, int end) {
        if(end < start) {
            throw std::runtime_error("Range is backwards!");
        }
        double each = 1.0 / ((end - start) + 1);
        Distribution d;
        MapType &map = d.map;
        for(int i = start; i <= end; ++i) {
            map.emplace(std::make_pair(i, each));
        }
        return d;
    }
    
    int Distribution::max() const noexcept {
        // std::map is sorted.
        return map.rbegin()->first;
    }
    
    int Distribution::min() const noexcept {
        // std::map is sorted.
        return map.begin()->first;
    }
    
    Distribution Distribution::convolveAdd(const Distribution &o)
    const noexcept {
        Distribution d;
        auto &m = d.map;
        int overallMin = std::min(min(), o.min());
        int overallMax = std::max(max(), o.max());
        int minPossible = min() + o.min();
        int maxPossible = max() + o.max();
        for(int i = minPossible; i <= maxPossible; ++i) {
            double sum = 0;
            for(int k = overallMin; k <= overallMax; ++k) {
                sum += (*this)[k] * o[i - k];
            }
            m.emplace(std::make_pair(i, sum));
        }
        return d;
    }
}
