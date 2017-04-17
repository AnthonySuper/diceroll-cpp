#ifndef _DICEROLL_DISTRIBUTION_HPP
#define _DICEROLL_DISTRIBUTION_HPP

#include <map>

namespace Diceroll {
    /**
     This class models a probabilty distribution.
     */
    class Distribution {
        using MapType = std::map<int, double>;
    public:
        static Distribution uniformRange(int start, int end);
        
        /**
         Obtain the probability of a given value i.
         If i is not in the map, 0.0 will be returned.
         */
        double operator[](int i) const;
        
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
    private:
        MapType map;
    };
}
#endif
