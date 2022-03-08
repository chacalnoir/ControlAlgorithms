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
 * A simple derivative controller using only float calculations (no doubles).
 * Maintains the previous error as the state.
 * 
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_DERIVATIVE_H
#define CONTROLALGORITHMS_DERIVATIVE_H

// Required to avoid divide by zero
#ifndef ZERO_DELTA
  #define ZERO_DELTA 0.0000001
#endif

namespace ControlAlgorithms {

class Derivative {
    public:
        Derivative() {};

        /**
         * The calculate function for the derivative controller
         * @param error: float error value
         * @param delta_t: float change in time since last call in correct time units
         * @return float: the resulting control signal
         */
        float calculate(float error, float delta_t);

        /**
         * Sets the gain for the controller
         * @param gain: float the gain
         */
        void set_gain(float gain) {
            gain_ = gain;
        }

        /**
         * Resets the internal state (the previous error)
         */
        void reset() {
            previous_error_ = 0.0;
        }

    private:
        // The integral gain
        float gain_{0.0};

        // The integrated error
        float previous_error_{0.0};
};

}  // namespace ControlAlgorithms

#endif
