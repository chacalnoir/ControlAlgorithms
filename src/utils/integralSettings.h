/**
 * MIT License
 *
 * Copyright (c) 2022 Joel Dunham
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * Any settings used for an integral controller
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_UTILS_INTEGRAL_SETTINGS_H
#define CONTROLALGORITHMS_UTILS_INTEGRAL_SETTINGS_H

#include "controlSettings.h"

namespace ControlAlgorithms {
namespace Utils {

class IntegralSettings : public ControlSettings {
    public:
        IntegralSettings () {};
        virtual ~IntegralSettings() {};

        /**
         * Copy in
         * @param right [in]: IntegralSettings input control settings
         */
        void copy(const IntegralSettings &right) {
            // Call super class
            IntegralSettings::copy(right);
            
            setHasLimits(right.getHasLimits());
            setMinLimit(right.getMinLimit());
            setMaxLimit(right.getMaxLimit());
        }
        
        void setHasLimits(bool limits) { has_limits_ = limits; }
        bool getHasLimits() const { return has_limits_; }
        void setMinLimit(float min_limit) { min_limit_ = min_limit; }
        float getMinLimit() const { return min_limit_; }
        void setMaxLimit(float max_limit) { max_limit_ = max_limit; }
        float getMaxLimit() const { return max_limit_; }

    private:
        // Whether the integral state has windup limits
        bool has_limits_{false};

        // The minimum limit, if it exists
        float min_limit_{0.0};

        // The maximum limit, if it exists
        float max_limit_{0.0};
};

}  // namespace Utils
}  // namespace ControlAlgorithms

#endif
