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
 * Stateless implementation of control algorithms
 * 
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#include "utilities.h"
#include <algorithm>

namespace ControlAlgorithms {
namespace Utils {

void Utilities::proportional(const ControlInput input, const ControlSettings settings, ControlOutput &out) {
    out.setControl(input.getError() * settings.getGain());
}

void Utilities::integral(const IntegralInput input, const IntegralSettings settings, IntegralOutput &out) {
    out.setControl(input.getError() * settings.getGain());

    // Update the integral state
    out.setIntegratedError(input.getIntegratedError() + input.getError() * input.getDeltaT());

    // Handle windup limits
    if(settings.getHasLimits()) {
        out.setIntegratedError(std::min(settings.getMaxLimit(), std::max(settings.getMinLimit(), out.getIntegratedError())));
    }

    // Calculate and return the control signal
    out.setControl(out.getIntegratedError() * settings.getGain());
}

void Utilities::derivative(const DerivativeInput input, const ControlSettings settings, DerivativeOutput &out) {
    // Update the derivative calculation
    float error_derivative = (input.getError() - input.getPreviousError()) / std::max(input.getDeltaT(), (float)ZERO_DELTA);

    // Save the previous error
    out.setPreviousError(input.getError());

    // Calculate and return the control signal
    out.setControl(error_derivative * settings.getGain());
}

}  // namespace Utils
}  // namespace ControlAlgorithms
