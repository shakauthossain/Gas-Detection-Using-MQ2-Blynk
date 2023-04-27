#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <Blynk.h>

BlynkTimer timer;

char auth[] = "";
char ssid[] = "";
char pass[] = "";

int n = 36;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(4,OUTPUT);
  timer.setInterval(1000L, sendUptime);
}

void sendUptime()
{
  Blynk.virtualWrite(V1, n);
}

void loop()
{
  Blynk.run();
  timer.run();
  n=analogRead(36);
  Serial.println(n);
  
  if(n>190)
  {
    digitalWrite(4,HIGH);
    delay(2000);  

  }
  else if(n<190)
  {
      digitalWrite(4,LOW);
      delay(2000);

  }
}
