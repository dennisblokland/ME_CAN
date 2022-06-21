#include <ME_CAN.h>

ME_CAN ME_can;
int id = 768;
byte data[8];

void setup()
{
    Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
    data[0] = random(0, 0x1C);
    data[1] = random(0, 0x20);
    data[2] = 0;
    data[3] = random(1000);
    data[4] = random(0, 0x27);
    data[5] = random(0, 0x10);
    data[6] = 0;
    data[7] = random(1000);
    if (ME_can.unpack_message(id, data, 8) < 0)
    {
        Serial.println(ME_can.RPM);
    }
    
    delay(100); 
}
