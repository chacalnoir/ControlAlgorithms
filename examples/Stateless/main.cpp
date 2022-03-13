/**
 * Example use of the PID control algorithms using the stateless utility class.
 * 
 * @author Joel Dunham <joel.ph.dunham@gmail.com>
 * @date 2022/03/08
 */

#include <pid/proportionalStateless.h>
#include <pid/integralStateless.h>
#include <pid/derivativeStateless.h>
#include <Arduino.h>

// Inputs
ControlAlgorithms::Base::ControlInput input_p;
ControlAlgorithms::PID::IntegralInput input_i;
ControlAlgorithms::PID::DerivativeInput input_d;
// Settings
ControlAlgorithms::Base::ControlSettings settings_p;
ControlAlgorithms::PID::IntegralSettings settings_i;
ControlAlgorithms::PID::DerivativeSettings settings_d;
// Outputs
ControlAlgorithms::Base::ControlOutput output_p;
ControlAlgorithms::PID::IntegralOutput output_i;
ControlAlgorithms::PID::DerivativeOutput output_d;

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
  settings_p.setGain(-0.4);

  // Integral
  settings_i.setGain(-0.2);
  settings_i.setHasLimits(true);
  settings_i.setMinLimit(-100.0);
  settings_i.setMaxLimit(100.0);

  // Derivative
  settings_d.setMinTimeStep(0.0000001);
  settings_d.setGain(-0.1);

  // Initialize some data
  output_i.setIntegratedError(0.0);
  output_d.setPreviousError(0.0);
}
 
void loop() {
  // Capture time for the delta time necessary for the integral and derivative parts of the controller
  msNow = millis();

  // Run the algorithm. 
  input_p.setError(errors[test_counter]);
  input_i.setError(errors[test_counter]);
  input_d.setError(errors[test_counter]);
  if(test_counter++ >= TEST_CASES) {
    test_counter = 0;
  }
  input_p.setDeltaT((float)(msNow - msLastTime) / 1000.0f);
  input_i.setDeltaT((float)(msNow - msLastTime) / 1000.0f);
  input_i.setIntegratedError(output_i.getIntegratedError());
  input_d.setDeltaT((float)(msNow - msLastTime) / 1000.0f);
  input_d.setPreviousError(output_d.getPreviousError());

  Serial.println("Test case");
  Serial.print("Error: ");
  Serial.println(input_p.getError());
  Serial.print("Delta T: ");
  Serial.println(input_p.getDeltaT());

  float control_value = 0.0;
  ControlAlgorithms::PID::ProportionalStateless::update(input_p, settings_p, output_p);
  Serial.print("P control: ");
  Serial.println(output_p.getControl());
  control_value += output_p.getControl();

  ControlAlgorithms::PID::IntegralStateless::update(input_i, settings_i, output_i);
  Serial.print("I control: ");
  Serial.println(output_i.getControl());
  control_value += output_i.getControl();

  ControlAlgorithms::PID::DerivativeStateless::update(input_d, settings_d, output_d);
  Serial.print("D control: ");
  Serial.println(output_d.getControl());
  control_value += output_d.getControl();

  Serial.print("Total control: ");
  Serial.println(control_value);

  delay(500);  // Run every 1/s second

  // For the next round
  msLastTime = msNow;
}
