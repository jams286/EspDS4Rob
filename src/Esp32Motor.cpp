// #include <Arduino.h>

// #define PWMA 19 // AIN2
// #define AIN1 18 // AIN1
// #define BIN1 16 // BIN4 RX2 
// #define PWMB 17 // BIN3 TX2
// #define ENABLE 2
// // #define PAUSEPIN 2

// // bool state = false;

// void forward(unsigned int speed);
// void backward(unsigned int speed);
// void left(unsigned int speed);
// void right(unsigned int speed);
// void stop(unsigned int speed);
// void shortStop(unsigned int speed);
// void Pause();

// void setup() 
// { 
//   Serial.begin(115200);
//   Serial.println("Ready.");  
//   // Setting Motor A
//   pinMode(AIN1, OUTPUT);
//   pinMode(PWMA, OUTPUT);
//   // Setting Motor B
//   pinMode(BIN1, OUTPUT);
//   pinMode(PWMB, OUTPUT);
//   // Set Init Speed (0-255)
//   analogWrite(PWMA, 127);
//   analogWrite(PWMB, 127);
//   // Setup Interrup pin
//   // pinMode(PAUSEPIN, INPUT_PULLUP);
//   // attachInterrupt(PAUSEPIN, Pause, FALLING);

//   // Init Enable
//   pinMode(ENABLE, OUTPUT);
//   digitalWrite(ENABLE, HIGH);
//   // stop(0);
//   digitalWrite(AIN1, LOW);
//   digitalWrite(BIN1, LOW);
//   analogWrite(PWMA, HIGH);
//   analogWrite(PWMB, HIGH);
// }

// void loop() 
// {
//   // delay(1000);
//   // forward(255);
// }

// void forward(unsigned int speed)
// {
//     digitalWrite(AIN1, LOW);
//     digitalWrite(BIN1, LOW);
//     analogWrite(PWMA, speed);
//     analogWrite(PWMB, speed);
// }

// void backward(unsigned int speed)
// {
//     digitalWrite(PWMA, LOW);
//     digitalWrite(PWMB, LOW);
//     analogWrite(AIN1, speed);
//     analogWrite(BIN1, speed);
// }

// void left(unsigned int speed)
// {
//     digitalWrite(AIN1, speed);
//     digitalWrite(BIN1, LOW);
//     analogWrite(PWMA, LOW);
//     analogWrite(PWMB, speed);
// }

// void right(unsigned int speed)
// {
//     digitalWrite(AIN1, LOW);
//     digitalWrite(BIN1, speed);
//     analogWrite(PWMA, speed);
//     analogWrite(PWMB, LOW);
// }

// void stop(unsigned int speed)
// {
//     digitalWrite(AIN1, LOW);
//     digitalWrite(BIN1, LOW);
//     analogWrite(PWMA, speed);
//     analogWrite(PWMB, speed);
// }

// void shortStop(unsigned int speed)
// {
//     digitalWrite(AIN1, HIGH);
//     digitalWrite(BIN1, HIGH);
//     analogWrite(PWMA, speed);
//     analogWrite(PWMB, speed);
// }

// void Pause()
// {
//     // state = !state;
//     stop(0);
//     digitalWrite(ENABLE,LOW);
// }