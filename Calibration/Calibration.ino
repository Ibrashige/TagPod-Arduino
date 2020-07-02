/**
 * Central class that operates the dispenser's data, sensors and actuators.
 * 
 * Relies on the tacuna systems knowledge base:
 https://tacunasystems.com/knowledge-base/load-cell-faq/
 *
 *
 */
 
const float offset = 4.1056; // offset for the load cell to indicate 0 load at 2.5 V
const float vpp = 0.0048828125; // 5V/1024 for ADC conversion
const float totalLoad = 12.5; // maximum load capacity 12.5 pounds
const float a = 1100; // Amplifier Gain
const float s = 0.0008998; // load cell sensitivity 
const float ve = 4.97; //Excitation voltage
float points;
float voltage;
float load;
float numerator; // numerator of load calculation
float voutmax; // denominator of load calculation

#define VOUT  A0

void setup() {
  
  Serial.begin(9600);
  Serial.println("Weighing code");
  
}

void loop() {
  calculatevoltage();
  calculateweight();
}

float calculatevoltage(){
  
  points = analogRead(VOUT)- offset; 
  voltage = points * vpp; 
  Serial.println(voltage);

  delay(3000);
}

void calculateweight(){
  numerator = totalLoad * (voltage-0.55);
  voutmax = s * a * ve;              // raw output voltage to its maximum rated capacity
  load = numerator/voutmax; // weight in lbs
  Serial.println(load);  

  delay(300);
}
