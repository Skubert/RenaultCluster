const int speedPin =  4;
const int rpmPin =  5;
const int leftIndicatorPin = 6;
const int rightIndicatorPin = 7;
const int handbrakePin = 8;
const int batteryPin = 9;
const int absPin = 10;
const int lowbeamPin = 11;
const int highbeamPin = 12;

int kphState = LOW;
int rpmState = LOW;

int rpm = 0;
int kph = 0;

unsigned long previousKphMicros = 0;
unsigned long previousRpmMicros = 0;

long rpmDivisor = 142000;
long kphDivisor = 400000;

String commandBuffer;
int semicolon = -1;

int findNextSemicolon(){
  semicolon = commandBuffer.indexOf(";");
}

void processCommand()
{  
  if (commandBuffer.startsWith("spd "))
  {
    commandBuffer.remove(0, 4);
    kph = commandBuffer.toInt();
    if (kph < 1)
      kph = 1;
  }
  else  if (commandBuffer.startsWith("rpm "))
  {
    commandBuffer.remove(0, 4);
    rpm = commandBuffer.toInt();
    if (rpm < 1)
      rpm = 1;
  }
  else if(commandBuffer.startsWith("left ")){
    commandBuffer.remove(0, 5);
    if(commandBuffer == "True"){
      digitalWrite(leftIndicatorPin, HIGH);
    }else{
      digitalWrite(leftIndicatorPin, LOW);
    }
  }
  else if(commandBuffer.startsWith("right ")){
    commandBuffer.remove(0, 6);
    if(commandBuffer == "True"){
      digitalWrite(rightIndicatorPin, HIGH);
    }else{
      digitalWrite(rightIndicatorPin, LOW);
    }
  }
  else if(commandBuffer.startsWith("abs ")){
    commandBuffer.remove(0, 4);
    if(commandBuffer == "True"){
      digitalWrite(absPin, HIGH);
    }else{
      digitalWrite(absPin, LOW);
    }
  }
  else
  {
    Serial.println("Error.");
  }
}

void setup() {
  // set the digital pin as output:

  pinMode(rpmPin, OUTPUT);
  pinMode(speedPin, OUTPUT);
  pinMode(leftIndicatorPin, OUTPUT);
  pinMode(rightIndicatorPin, OUTPUT);
  pinMode(handbrakePin, OUTPUT);
  pinMode(batteryPin, OUTPUT);
  pinMode(absPin, OUTPUT);
  pinMode(lowbeamPin, OUTPUT);
  pinMode(highbeamPin, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  while (Serial.available() > 0) {
    int inChar = Serial.read();

    if (inChar == '\n')
    {
      processCommand();
      commandBuffer = "";
    }
    else
    {
      commandBuffer += (char)inChar;
    }
  }

  unsigned long currentMicros = micros();

  if (currentMicros - previousKphMicros >= kphDivisor / kph && kph > 0) {
    previousKphMicros = currentMicros;

    if (kphState == LOW) {
      kphState = HIGH;
    } else {
      kphState = LOW;
    }
    digitalWrite(speedPin, kphState);
  }

  if (currentMicros - previousRpmMicros >= rpmDivisor / rpm && rpm > 0) {
    previousRpmMicros = currentMicros;

    if (rpmState == LOW) {
      rpmState = HIGH;
    } else {
      rpmState = LOW;
    }
    digitalWrite(rpmPin, rpmState);
  }
}
