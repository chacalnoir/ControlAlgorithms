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
 * Maintains the integrated error as the state.
 * 
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_INTEGRAL_H
#define CONTROLALGORITHMS_INTEGRAL_H

namespace ControlAlgorithms {

class Integral {
    public:
        Integral() {};

        /**
         * The calculate function for the integral controller
         * @param error: float error value
         * @param delta_t: float change in time since last call in correct time units
         * @return float: the resulting control signal
         */
        float calculate(float error, float delta_t);

        /**
         * Set the windup limits
         * @param has_limits: bool whether the integral controller has limits
         * @param min_limit: float the lower limit
         * @param max_limit: float the upper limit
         */
        void set_limits(bool has_limits, float min_limit=0.0, float max_limit=0.0) {
            has_limits_ = has_limits;
            min_limit_ = min_limit;
            max_limit_ = max_limit;
        }

        /**
         * Sets the gain for the controller
         * @param gain: float the gain
         */
        void set_gain(float gain) {
            gain_ = gain;
        }

        /**
         * Resets the internal state (the integrated error)
         */
        void reset() {
            integral_state_ = 0.0;
        }

    private:
        // The integral gain
        float gain_{0.0};

        // The integrated error
        float integral_state_{0.0};

        // Whether the integral state has windup limits
        bool has_limits_{false};

        // The minimum limit, if it exists
        float min_limit_{0.0};

        // The maximum limit, if it exists
        float max_limit_{0.0};
};

}  // namespace ControlAlgorithms

#endif
