#include<Servo.h>
Servo M;
int HEsense,HEpin=A0,HED=0;
int x;
void setup() {
    pinMode(7,OUTPUT);
    digitalWrite(7,LOW);
    pinMode(HEpin,INPUT);
    M.attach(A2);
    Serial.begin(9600);
    M.write(86);
}
int HEADC()   //Hall Effect Analog To Digit Converter
{
    HEsense=analogRead(HEpin);
    Serial.print(HEsense);
    Serial.print(" ");
    if(HEsense<=611 && HEsense>=576)
        HED=600;
    else if(HEsense>=647)
        HED=650;
    else if(HEsense<=557)
        HED=550;
    return HED;
}

void loop() {
    x=HEADC();
    Serial.println(x);
    delay(10);
}
