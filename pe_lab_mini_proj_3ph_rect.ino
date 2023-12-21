// Define the SCR gate pins
const int G1 = 2;  // Replace with the actual pin numbers
const int G2 = 3;
const int G3 = 4;
const int G4 = 5;
const int G5 = 6;
const int G6 = 7;

// Define the time parameters
const float timePeriod = 0.02;  // Time period in seconds
const float pulseWidth = 0.02 * 0.05;  // Pulse width (5% of time period)
float a = 20.0;  // Phase angle in degrees (initial value)



void setup() {
  // Configure SCR gate pins as output
  pinMode(G1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(G3, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(G5, OUTPUT);
  pinMode(G6, OUTPUT);  
}

void loop() {
  
  // Calculate the phase delays in microseconds
  long delayG1 = long(a * timePeriod * 1000000 / 360.0);
  long pulseOn = long(pulseWidth * 1000000);
  long delay60degEFF = long(60 * timePeriod * 1000000 / 360.0 - pulseWidth * 1000000);

  delayMicroseconds(delayG1);
  // Trigger the SCRs with phase delays
  digitalWrite(G1, HIGH);
  delayMicroseconds(pulseOn);
  digitalWrite(G1, LOW);

  delayMicroseconds(delay60degEFF);

  digitalWrite(G6, HIGH);
  delayMicroseconds(pulseOn);
  digitalWrite(G6, LOW);

  delayMicroseconds(delay60degEFF);

  digitalWrite(G3, HIGH);
  delayMicroseconds(pulseOn);
  digitalWrite(G3, LOW);
  
  delayMicroseconds(delay60degEFF);

  digitalWrite(G2, HIGH);
  delayMicroseconds(pulseOn);
  digitalWrite(G2, LOW);
  
  delayMicroseconds(delay60degEFF);

  digitalWrite(G5, HIGH);
  delayMicroseconds(pulseOn);
  digitalWrite(G5, LOW);
  
  delayMicroseconds(delay60degEFF);

  digitalWrite(G4, HIGH);
  delayMicroseconds(pulseOn);
  digitalWrite(G4, LOW);
  
  delayMicroseconds(delay60degEFF - delayG1);

  // Increase 'a' for the next cycle (adjust as needed)
  // a += 0.1;  // You can adjust the increment value

  // Add a delay before the next cycle (adjust as needed)
  // delay(1000);  // Delay between cycles in milliseconds
}
