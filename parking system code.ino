#include <RFID.h>
#define SS1_PIN 10
#define SS2_PIN 3
#define RST_PIN 9
#define Red_Led1 2
#define Yellow_Led1 4
#define Buzzer_NO1 5
#define Red_Led2 6
#define Yellow_Led2 7
#define Buzzer_NO2 8

RFID rfid1(SS1_PIN, RST_PIN);
RFID rfid2(SS2_PIN, RST_PIN);
String rfidCard1 , rfidCard2;
void setup() 
{
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
  SPI.begin();
  rfid1.init();
  rfid2.init();
  pinMode(Red_Led1, OUTPUT);
  pinMode(Yellow_Led1, OUTPUT);
  pinMode(Buzzer_NO1, OUTPUT);
  pinMode(Buzzer_NO2, OUTPUT);
  pinMode(Red_Led2, OUTPUT);
  pinMode(Yellow_Led2, OUTPUT);
}
void loop() 
{
  if (rfid1.isCard()) 
  {
    if (rfid1.readCardSerial())
    {
      rfidCard1 = String(rfid1.serNum[0]) + " " + String(rfid1.serNum[1]) + " " + String(rfid1.serNum[2]) + " " + String(rfid1.serNum[3]);
      Serial.println("RF ID 1 = " + rfidCard1);
      if (rfidCard1 == "240 178 150 25") 
      {
        
        digitalWrite(Red_Led1, LOW);
        digitalWrite(Yellow_Led1,HIGH);
        
        digitalWrite(Buzzer_NO1, HIGH);
        delay(500);
        digitalWrite(Buzzer_NO1, LOW);
        digitalWrite(Yellow_Led1,LOW);
        Serial.println("ATD+919960415919;");
       delay(1000);
      } 
      else 
      {
        digitalWrite(Red_Led1, HIGH);
        digitalWrite(Yellow_Led1, LOW);
        digitalWrite(Buzzer_NO1, HIGH);
        delay(300);
        digitalWrite(Buzzer_NO1, LOW);
        delay(200);
        digitalWrite(Buzzer_NO1, HIGH);
        delay(300);      
        digitalWrite(Buzzer_NO1, LOW);
        digitalWrite(Red_Led1, LOW);
        delay(1000);
      }
    }
    rfid1.halt();
  }
  
  if (rfid2.isCard()) 
  {
    if (rfid2.readCardSerial())
    {
      rfidCard2 = String(rfid2.serNum[0]) + " " + String(rfid2.serNum[1]) + " " + String(rfid2.serNum[2]) + " " + String(rfid2.serNum[3]);
      Serial.println("RF ID 2 = " + rfidCard2);
      if (rfidCard2 == "33 94 184 38") 
      {
        digitalWrite(Red_Led2, LOW);
        digitalWrite(Yellow_Led2, HIGH);
        digitalWrite(Buzzer_NO2, HIGH);
        delay(500);
        digitalWrite(Buzzer_NO2, LOW);
        digitalWrite(Yellow_Led2, LOW);
        Serial.println("ATD+919960415919;");
        delay(1000);
        
      } 
      else 
      {
        digitalWrite(Red_Led2, HIGH);
        digitalWrite(Yellow_Led2, LOW);
        digitalWrite(Buzzer_NO2, HIGH);
        delay(300);
        digitalWrite(Buzzer_NO2, LOW);
        delay(200);
        digitalWrite(Buzzer_NO2, HIGH);
        delay(300);      
        digitalWrite(Buzzer_NO2, LOW);
        delay(1000);
        digitalWrite(Red_Led2, LOW);
      }
    }
    rfid2.halt();
  }
}
