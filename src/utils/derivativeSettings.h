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
 * Any settings used for a derivative controller
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_UTILS_DERIVATIVE_SETTINGS_H
#define CONTROLALGORITHMS_UTILS_DERIVATIVE_SETTINGS_H

#include "controlSettings.h"

namespace ControlAlgorithms {
namespace Utils {

class DerivativeSettings : public ControlSettings {
    public:
        DerivativeSettings () {};
        virtual ~DerivativeSettings() {};

        /**
         * Copy in
         * @param right [in]: DerivativeSettings input control settings
         */
        void copy(const DerivativeSettings &right) {
            // Call super class
            DerivativeSettings::copy(right);
            
            setMinTimeStep(right.getMinTimeStep());
        }
        
        void setMinTimeStep(bool min_time_step) { min_time_step_ = min_time_step; }
        float getMinTimeStep() const { return min_time_step_; }

    private:
        // The minimum time step allowed
        float min_time_step_{0.0000001};
};

}  // namespace Utils
}  // namespace ControlAlgorithms

#endif
