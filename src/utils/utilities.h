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
 * Utilities class for any control algorithms that can have settings and/or state passed in.
 *   These are all static, stateless functions.
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_UTILS_UTILITIES_H
#define CONTROLALGORITHMS_UTILS_UTILITIES_H

#include "controlSettings.h"
#include "integralSettings.h"
#include "derivativeSettings.h"
#include "controlInput.h"
#include "controlOutput.h"
#include "integralInput.h"
#include "integralOutput.h"
#include "derivativeInput.h"
#include "derivativeOutput.h"

namespace ControlAlgorithms {
namespace Utils {

class Utilities {
    public:
        /**
         * The calculate function for the proportional controller
         * @param input [in]: ControlInput values used to calculate the control signal
         * @param settings [in]: ControlSettings the controller settings
         * @param out [out]: ControlOutput the output signal and any additional/changed data used for continued computations
         */
        static void proportional(const ControlInput input, const ControlSettings settings, ControlOutput &out);

        /**
         * The calculate function for the integral controller
         * @param input [in]: IntegralInput values used to calculate the control signal
         * @param settings [in]: IntegralSettings the controller settings
         * @param out [out]: IntegralOutput the output signal and any additional/changed data used for continued computations
         */
        static void integral(const IntegralInput input, const IntegralSettings settings, IntegralOutput &out);

        /**
         * The calculate function for the derivative controller
         * @param input [in]: DerivativeInput values used to calculate the control signal
         * @param settings [in]: DerivativeSettings the controller settings
         * @param out [out]: DerivativeOutput the output signal and any additional/changed data used for continued computations
         */
        static void derivative(const DerivativeInput input, const DerivativeSettings settings, DerivativeOutput &out);

    private:
        // Private constructor to ensure only the static/stateless functions are used.
        Utilities() {};
};

}  // namespace Utils
}  // namespace ControlAlgorithms

#endif
