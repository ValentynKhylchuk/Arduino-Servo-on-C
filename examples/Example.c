#include "Servo.h"

#define SERVO_PIN 6
int servo_id = -1;

void setup()
{
    servo_id = Servo_addServo();
    if(servo_id < 0)
    {
        // No luck (
        return;
    }

    Servo_attach(servo_id, SERVO_PIN);
}

void loop()
{
    if(servo_id >= 0)
    {
        Servo_write(servo_id, 0);
    }
    delay(2000);

    if(servo_id >= 0)
    {
        Servo_write(servo_id, 180);
    }
    delay(2000); 
}