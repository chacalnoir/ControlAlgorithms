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
 * A simple proportional controller using only float calculations (no doubles).
 * 
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_PROPORTIONAL_H
#define CONTROLALGORITHMS_PROPORTIONAL_H

#include "utils/controlInput.h"
#include "utils/controlOutput.h"
#include "utils/controlSettings.h"
#include "utils/utilities.h"

namespace ControlAlgorithms {

class Proportional {
    public:
        Proportional() {};
        
        /**
         * Set the controller settings
         * @param settings [in]: Utils::ControlSettings controller settings
         */
        void setSettings(const Utils::ControlSettings &settings) {
            settings_.copy(settings);
        }

        /**
         * The calculate function for the proportional controller
         * @param input [in]: Utils::ControlInput values used to calculate the control signal
         * @param out [out]: Utils::ControlOutput the output signal and any additional/changed data used for continued computations
         */
        void update(const Utils::ControlInput input, Utils::ControlOutput &out) {
            Utils::Utilities::proportional(input, settings_, out);
        }

    private:
        Utils::ControlSettings settings_;
};

}  // namespace ControlAlgorithms

#endif
