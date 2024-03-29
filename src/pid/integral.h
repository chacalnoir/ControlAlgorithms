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
 * A simple integral controller using only float calculations (no doubles).
 * 
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_INTEGRAL_H
#define CONTROLALGORITHMS_INTEGRAL_H

#include <pid/integralInput.h>
#include <pid/integralSettings.h>
#include <pid/integralOutput.h>
#include <pid/integralStateless.h>

namespace ControlAlgorithms {
namespace PID {

class Integral {
    public:
        Integral() {};
        virtual ~Integral() {};
        
        /**
         * Set the controller settings
         * @param settings [in]: IntegralSettings controller settings
         */
        virtual void setSettings(const IntegralSettings &settings) {
            settings_.copy(settings);
        }

        /**
         * The calculate function for the integral controller
         * @param input [in]: Base::ControlInput values used to calculate the control signal
         * @param out [out]: Base::ControlOutput the output signal and any additional/changed data used for continued computations
         */
        virtual void update(const Base::ControlInput input, Base::ControlOutput &out) {
            // Set the input using the state
            static_cast<Base::ControlInput>(input_with_state_).copy(input);
            input_with_state_.setIntegratedError(state_.getIntegratedError());

            // Run the update
            IntegralStateless::update(input_with_state_, settings_, state_);

            // Copy to output
            out.copy(static_cast<Base::ControlOutput>(state_));
        }

        /**
         * Reset the internal state
         */
        virtual void reset() {
            state_.setIntegratedError(0.0);
        }

        virtual bool isStateful() { return true; }

    private:
        // The stored settings
        IntegralSettings settings_;

        // Contains all required state info
        IntegralOutput state_;

        // Used for the internal call with state
        IntegralInput input_with_state_;
};

}  // namespace PID
}  // namespace ControlAlgorithms

#endif
