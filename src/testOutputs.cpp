// #include <Arduino.h>

// #define PWMB 19 // BIN4
// #define BIN1 18 // BIN3
// #define AIN1 16 // AIN2 RX2 
// #define PWMA 17 // AIN1 TX2
// #define ENABLE 2
// // #define PAUSEPIN 2

// // bool state = false;

// void forward(unsigned int speed);
// void backward(unsigned int speed);
// void left(unsigned int speed);
// void right(unsigned int speed);
// void stop();
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
// //   analogWrite(PWMA, 127);
// //   analogWrite(PWMB, 127);
//   // Setup Interrup pin
//   // pinMode(PAUSEPIN, INPUT_PULLUP);
//   // attachInterrupt(PAUSEPIN, Pause, FALLING);

//   // Init Enable
//   pinMode(ENABLE, OUTPUT);
//   digitalWrite(ENABLE, HIGH);
//   stop();  
// }

// void loop() 
// {    
//    // forward
// //    analogWrite(AIN1, 0);
// //    analogWrite(PWMA, 255);
// //    delay(5000);
// //    analogWrite(PWMA, 0);
// //    analogWrite(AIN1, 255);
// //    delay(5000);
// forward(255);
// delay(3000);
// backward(255);
// delay(3000);

// }

// void forward(unsigned int speed)
// {
//     Serial.println("Forward.");  
//     analogWrite(AIN1, 0);
//     analogWrite(BIN1, 0);
//     analogWrite(PWMA, speed);
//     analogWrite(PWMB, speed);
// }

// void backward(unsigned int speed)
// {
//     Serial.println("Backward.");  
//     analogWrite(PWMA, 0);
//     analogWrite(PWMB, 0);
//     analogWrite(AIN1, speed);
//     analogWrite(BIN1, speed);
// }

// void left(unsigned int speed)
// {
//     Serial.println("Left.");  
//     analogWrite(AIN1, speed);
//     analogWrite(BIN1, 0);
//     analogWrite(PWMA, 0);
//     analogWrite(PWMB, speed);
// }

// void right(unsigned int speed)
// {
//     Serial.println("Right.");  
//     analogWrite(AIN1, 0);
//     analogWrite(BIN1, speed);
//     analogWrite(PWMA, speed);
//     analogWrite(PWMB, 0);
// }

// void stop()
// {
//     Serial.println("Stop.");  
//     analogWrite(AIN1, 0);
//     analogWrite(BIN1, 0);
//     analogWrite(PWMA, 0);
//     analogWrite(PWMB, 0);
// }

// void shortStop(unsigned int speed)
// {
//     Serial.println("Short Stop.");  
//     analogWrite(AIN1, 255);
//     analogWrite(BIN1, 255);
//     analogWrite(PWMA, speed);
//     analogWrite(PWMB, speed);
// }

// void Pause()
// {
//     // state = !state;
//     stop();
//     digitalWrite(ENABLE,LOW);
// }