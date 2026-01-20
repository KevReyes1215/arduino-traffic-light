int green = 3;
int yellow = 4;
int red = 5;
//
int button = 8;
int white = 12;
int redP = 13;
//
unsigned long lastTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(green, OUTPUT);   // Green LED
  pinMode(yellow, OUTPUT);  // Yellow LED
  pinMode(red, OUTPUT);     // Red LED

  pinMode(button, INPUT);  // Declares pin 8 as input (button)

  pinMode(white, OUTPUT);  // White LED
  pinMode(redP, OUTPUT);   // Red LED
}

void loop() {
  // put your main code here, to run repeatedly:

  trafficLightCycle();
}


// function bellow //
void greenLightDelay() {  // works

  while (millis() - lastTime <= 10000) { // millis goes up no delay subtract the lastTime (<1000) (had help with AI)
    if (digitalRead(8) == HIGH) { // checks if button is pressed with no delay from while loop
    Serial.println("User has pressed button!");
    break;

    }
  }
  Serial.println("Continuing cycle...");
}



void trafficLightCycle() {  // works
  Serial.println("🟢🚷 CYCLE STARTS");
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  //
  digitalWrite(white, LOW);
  digitalWrite(redP, HIGH);

  lastTime = millis(); // records last time before entering while loop (had help with AI)
  greenLightDelay();  //checks if pedestrian button is pressed

  Serial.println("🟡");
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(3000);

  Serial.println("🔴");
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(2000);

  Serial.println("🚶‍♂️");
  digitalWrite(white, HIGH);
  digitalWrite(redP, LOW);
  delay(5000);

  Serial.println("⏳🏃‍♂️");
  digitalWrite(white, LOW);
  for (int i = 0; i < 5; i++) {
    digitalWrite(redP, HIGH);
    delay(500);

    digitalWrite(redP, LOW);
    delay(500);
  }

  Serial.println("🚷");
  digitalWrite(white, LOW);
  digitalWrite(redP, HIGH);
  delay(2000);

  Serial.println("🟢");
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
}