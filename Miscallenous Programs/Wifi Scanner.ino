#include "ESP8266WiFi.h "
const int RSSI_MAX =-50;
const int RSSI_MIN =-100;

const int displayEnc =0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println("ESP wifi scan");
WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(500);
Serial.println("Setup complete");

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Wifi scan started");
int n = WiFi.scanNetworks();
Serial.println("Wifi scan complete");
if (n==0)
  Serial.println("No network found");
else
{
  Serial.print(n);
  Serial.println(" networks found");
  for (int i=0;i<n;++i){
    Serial.print(i+1);
    Serial.print(". ");
    Serial.print(WiFi.SSID(i));
    Serial.print(WiFi.RSSI(i));
    Serial.print("dBm (");
    Serial.print(dBmtoPercentage(WiFi.RSSI(i)));
    Serial.print("%)");
    if(WiFi.encryptionType(i)== ENC_TYPE_NONE)
      Serial.println(" OPEN NETWORK  ");
    else
      Serial.println();

     delay(100);
  }
}
Serial.println("");
delay(5000);
WiFi.scanDelete();
}

int dBmtoPercentage(int dBm)
{
  int quality;
  if(dBm<=RSSI_MIN)
    quality = 0;
  else if(dBm>=RSSI_MAX)
    quality = 100;
  else
    quality = 2*(dBm + 100);
   return quality;  
}
