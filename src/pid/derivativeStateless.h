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
 * Stateless version of derivative control algorithm
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_PID_DERIVATIVE_STATELESS_H
#define CONTROLALGORITHMS_PID_DERIVATIVE_STATELESS_H

#include <pid/derivativeInput.h>
#include <pid/derivativeSettings.h>
#include <pid/derivativeOutput.h>

namespace ControlAlgorithms {
namespace PID {

class DerivativeStateless {
    public:
        /**
         * The calculate function for the proportional controller
         * @param input [in]: DerivativeInput values used to calculate the control signal
         * @param settings [in]: DerivativeSettings the controller settings
         * @param out [out]: DerivativeOutput the output signal and any additional/changed data used for continued computations
         */
        static void update(const DerivativeInput input, const DerivativeSettings settings, DerivativeOutput &out);
    private:
        // Private constructor to ensure only the static/stateless functions are used.
        DerivativeStateless() {};
};

}  // namespace PID
}  // namespace ControlAlgorithms

#endif  // CONTROLALGORITHMS_PID_DERIVATIVE_STATELESS_H