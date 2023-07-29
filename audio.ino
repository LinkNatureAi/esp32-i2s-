#include <Arduino.h>
#include <WiFi.h>
#include <Audio.h>

#define I2S_DOUT      25
#define I2S_BCLK      27
#define I2S_LRC       26

const char* ssid = "POCO X3 Pro";
const char* password = "1234567890";

Audio audio;

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(1000); 
    Serial.print("."); 
  }
  delay(2000);
  Serial.println("conected!");
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(100);
  audio.connecttospeech("hello where are you from!", "en");
}

void loop(){ 

  audio.loop();

}

void audio_info(const char *info) {
  Serial.print("audio_info: "); Serial.println(info); }
