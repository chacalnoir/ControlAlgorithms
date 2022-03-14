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
 * Example use of the PID control algorithms using the stateful classes.
 * 
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#include <pid/proportional.h>
#include <pid/integral.h>
#include <pid/derivative.h>
#include <Arduino.h>

// These are each defined separately so the user can mix and match as they choose.
ControlAlgorithms::PID::Proportional control_p;
ControlAlgorithms::PID::Integral control_i;
ControlAlgorithms::PID::Derivative control_d;
// In/out information
ControlAlgorithms::Base::ControlInput input;
ControlAlgorithms::Base::ControlOutput output;

// Timing
uint64_t msNow{0L};
uint64_t msLastTime{0L};

const uint8_t TEST_CASES = 20;

// The test cases
float errors[TEST_CASES] =
  {0.1, -0.5, 1.0, -1.5, 0.0, 2.5, -10.5, 15.0, 0.2, -0.4, -2.1, -1.1, 0.6, 1.4, 3.8, 5.9, 6.8, 5.1, 2.3, 0.2};
uint8_t test_counter{0};

void setup() {
  // Start serial for debugging
  Serial.begin(115200);
  while(!Serial) {}

  // Set appropriate settings
  // Proportional
  ControlAlgorithms::Base::ControlSettings p_settings;
  p_settings.setGain(-0.4);

  // Integral
  ControlAlgorithms::PID::IntegralSettings i_settings;
  i_settings.setGain(-0.2);
  i_settings.setHasLimits(true);
  i_settings.setMinLimit(-100.0);
  i_settings.setMaxLimit(100.0);

  // Derivative
  ControlAlgorithms::PID::DerivativeSettings d_settings;
  d_settings.setMinTimeStep(0.0000001);
  d_settings.setGain(-0.1);

  // Set to the controllers
  control_p.setSettings(p_settings);
  control_i.setSettings(i_settings);
  control_d.setSettings(d_settings);
}
 
void loop() {
  // Capture time for the delta time necessary for the integral and derivative parts of the controller
  msNow = millis();

  // Run the algorithm. 
  input.setError(errors[test_counter]);
  if(test_counter++ >= TEST_CASES) {
    test_counter = 0;
  }
  input.setDeltaT((float)(msNow - msLastTime) / 1000.0f);
  Serial.println("Test case");
  Serial.print("Error: ");
  Serial.println(input.getError());
  Serial.print("Delta T: ");
  Serial.println(input.getDeltaT());

  float control_value = 0.0;
  control_p.update(input, output);
  Serial.print("P control: ");
  Serial.println(output.getControl());
  control_value += output.getControl();

  control_i.update(input, output);
  Serial.print("I control: ");
  Serial.println(output.getControl());
  control_value += output.getControl();

  control_d.update(input, output);
  Serial.print("D control: ");
  Serial.println(output.getControl());
  control_value += output.getControl();

  Serial.print("Total control: ");
  Serial.println(control_value);

  delay(500);  // Run every 1/s second

  // For the next round
  msLastTime = msNow;
}
