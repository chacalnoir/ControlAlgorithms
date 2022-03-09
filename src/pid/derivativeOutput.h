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
 * Output class for derivative controller
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_PID_DERIVATIVE_OUTPUT_H
#define CONTROLALGORITHMS_PID_DERIVATIVE_OUTPUT_H

#include <base/controlOutput.h>

namespace ControlAlgorithms {
namespace PID {

class DerivativeOutput: public Base::ControlOutput {
    public:
        DerivativeOutput () {};
        virtual ~DerivativeOutput() {};

        /**
         * Copy in
         * @param right [in]: DerivativeOutput input
         */
        void copy(const DerivativeOutput &right) {
            // Super call
            Base::ControlOutput::copy(right);

            setPreviousError(right.getPreviousError());
        }

        void setPreviousError(float previous_error) { previous_error_ = previous_error; }
        float getPreviousError() const { return previous_error_; }

    private:
        // The previous error
        float previous_error_{0.0};
};

}  // namespace PID
}  // namespace ControlAlgorithms

#endif
