int offset = 510;
const float vpp = 0.0048828125;
int points;
float voltage;
float amperage;
#define VOUT  A0

void setup() {
  Serial.begin(9600);
  Serial.println("EMBSGB200 calibration sketch");

  long int offset;
  //float Weight = ;
  
}

void loop() {
  calculatevoltage();
}

float calculatevoltage(){
  points = analogRead(VOUT);//- offset;
  voltage = points * vpp;
  amperage = voltage / 0.185;
  Serial.println(points);
}
