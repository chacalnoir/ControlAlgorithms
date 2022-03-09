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
 * Output class for integral controller
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_PID_INTEGRAL_OUTPUT_H
#define CONTROLALGORITHMS_PID_INTEGRAL_OUTPUT_H

#include <base/controlOutput.h>

namespace ControlAlgorithms {
namespace PID {

class IntegralOutput: public Base::ControlOutput {
    public:
        IntegralOutput () {};
        virtual ~IntegralOutput() {};

        /**
         * Copy in
         * @param right [in]: IntegralOutput input
         */
        void copy(const IntegralOutput &right) {
            // Super call
            Base::ControlOutput::copy(right);

            setIntegratedError(right.getIntegratedError());
        }

        void setIntegratedError(float int_error) { integrated_error_ = int_error; }
        float getIntegratedError() const { return integrated_error_; }

    private:
        // The current integrated error
        float integrated_error_{0.0};
};

}  // namespace PID
}  // namespace ControlAlgorithms

#endif
