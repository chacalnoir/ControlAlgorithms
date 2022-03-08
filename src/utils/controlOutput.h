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
 * Base class output for all control algorithms
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_UTILS_CONTROL_OUTPUT_H
#define CONTROLALGORITHMS_UTILS_CONTROL_OUTPUT_H

namespace ControlAlgorithms {
namespace Utils {

class ControlOutput {
    public:
        ControlOutput () {};

        /**
         * Copy in
         * @param right [in]: ControlOutput input
         */
        void copy(const ControlOutput &right) {
            setControl(right.getControl());
        }

        void setControl(float control) { control_ = control; }
        float getControl() const { return control_; }

    private:
        // The current control signal
        float control_{0.0};
};

}  // namespace Utils
}  // namespace ControlAlgorithms

#endif
