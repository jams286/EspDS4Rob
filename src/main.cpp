#include <Arduino.h>
#include <PS4Controller.h>

#define PWMB 19 // BIN4
#define BIN1 18 // BIN3
#define AIN1 16 // AIN2 RX2 
#define PWMA 17 // AIN1 TX2
#define ENABLE 2

unsigned long lastTimeStamp = 0;
unsigned int gSpeed = 0;

void forward(unsigned int speed);
void backward(unsigned int speed);
void left(unsigned int speed);
void right(unsigned int speed);
void stop();
void shortStop(unsigned int speed);
void Pause();
void notify();
void onConnect();
void onDisConnect();
void onSetSpeed();

bool retro = false;

void setup() 
{

    Serial.begin(115200);
    PS4.attach(notify);
    PS4.attachOnConnect(onConnect);  
    PS4.attachOnDisconnect(onDisConnect);   
    PS4.begin();
    Serial.println("Ready.");  
    // Setting Motor A
    pinMode(AIN1, OUTPUT);
    pinMode(PWMA, OUTPUT);
    // Setting Motor B
    pinMode(BIN1, OUTPUT);
    pinMode(PWMB, OUTPUT);
    // Init Enable
    pinMode(ENABLE, OUTPUT);
    digitalWrite(ENABLE, HIGH);    
    stop();  
}

void loop() 
{    

}
void onSetSpeed(unsigned int spd)
{    
    gSpeed = spd;
}

void forward(unsigned int speed)
{
    // Serial.println("Forward.");  
    analogWrite(AIN1, 0);
    analogWrite(BIN1, 0);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}

void backward(unsigned int speed)
{
    // Serial.println("Backward.");  
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    analogWrite(AIN1, speed);
    analogWrite(BIN1, speed);
}

void right(unsigned int speed)
{
    Serial.println("Right.");  
    analogWrite(AIN1, speed);
    analogWrite(BIN1, 0);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, speed);
}

void left(unsigned int speed)
{
    Serial.println("Left.");  
    analogWrite(AIN1, 0);
    analogWrite(BIN1, speed);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, 0);
}

void stop()
{
    Serial.println("Stop.");  
    analogWrite(AIN1, 0);
    analogWrite(BIN1, 0);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
}

void shortStop(unsigned int speed)
{
    Serial.println("Short Stop.");  
    analogWrite(AIN1, 255);
    analogWrite(BIN1, 255);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}

void Pause()
{
    // state = !state;
    stop();
    digitalWrite(ENABLE,LOW);
}

void notify()
{    
    
    if (PS4.Square())
    {
        PS4.setLed(255,0,255);
        PS4.sendToController();
        left(255);
    }
    else if (PS4.Circle())
    {
        PS4.setLed(255,0,0);
        PS4.sendToController();
        right(255);
    }
    else if (PS4.Triangle())
    {
        PS4.setLed(0,255,0);
        PS4.sendToController();
        retro = false;
    }
    else if (PS4.Cross())
    {
        PS4.setLed(0,0,255);
        PS4.sendToController();
        retro = true;
    }
    else if (PS4.PSButton()) 
    {
        PS4.setLed(255,255,255);
        PS4.sendToController();  
        stop();
    }
    
    char messageString[200];
    sprintf(messageString, "%3d,%3d,%3d,%3d,Speed:%4d,Stop:%3d,Charging:%3d,Battery:%4d,",
    PS4.Square(),
    PS4.Cross(),
    PS4.Circle(),
    PS4.Triangle(),
    PS4.L2Value(),
    PS4.PSButton(),
    PS4.Charging(),
    PS4.Battery());

    //Only needed to print the message properly on serial monitor. Else we dont need it.
    if (millis() - lastTimeStamp > 50)
    {
        Serial.println(messageString);
        lastTimeStamp = millis();
        if (!retro)
        {
            forward(PS4.L2Value());
        }
        else
        {
            backward(PS4.L2Value());
        }
    }
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}