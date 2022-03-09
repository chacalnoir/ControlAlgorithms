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
 * Settings used for all controls
 *
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#ifndef CONTROLALGORITHMS_BASE_CONTROL_SETTINGS_H
#define CONTROLALGORITHMS_BASE_CONTROL_SETTINGS_H

namespace ControlAlgorithms {
namespace Base {

class ControlSettings {
    public:
        ControlSettings() {};
        virtual ~ControlSettings() {};

        /**
         * Copy in
         * @param right [in]: ControlSettings input control settings
         */
        void copy(const ControlSettings &right) {
            setGain(right.getGain());
        }
    
        void setGain(float gain) { gain_ = gain; }
        float getGain() const { return gain_; }
    private:
        // The gain
        float gain_{0.0};
};

}  // namespace Base
}  // namespace ControlAlgorithms

#endif
