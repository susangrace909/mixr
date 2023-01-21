#include <NeoPixelBus.h>

#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

#define USE_SERIAL Serial

WiFiMulti wifiMulti;
const uint16_t PixelCount = 16; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 2;  // make sure to set this to the correct pin, ignored for Esp8266

#define colorSaturation 128

NeoPixelBus<NeoGrbwFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

void setup()
{

  USE_SERIAL.begin(115200);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for(uint8_t t = 4; t > 0; t--) {
      USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
      USE_SERIAL.flush();
      delay(1000);
  }

  wifiMulti.addAP("DavidsPocketNet", "fishandchipsuk");
  
  USE_SERIAL.println();
  USE_SERIAL.println("Initializing...");
  USE_SERIAL.flush();

  // this resets all the neopixels to an off state
  strip.Begin();
  strip.Show();

  USE_SERIAL.println();
  USE_SERIAL.println("Running...");
}


void loop()
{
  String source = getSourceCodeFromEndpoint("http://www.timbrack.de/");

  USE_SERIAL.println(source);

  delay(5000);
}

String getSourceCodeFromEndpoint(String endpointUrl)
{
  String payload;

      // wait for WiFi connection
    if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");

        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin(endpointUrl); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) 
        {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
              payload = http.getString();
            }
        }
        else 
        {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    return payload;
}

// Fill the dots one after the other with a color
void colorWipe(RgbColor c, uint8_t wait) 
{
  for(uint16_t i=0; i<PixelCount; i++) 
  {
    strip.SetPixelColor(i, c);
    strip.Show();

    delay(wait);
  }

  delay(500);

  for(uint16_t i=0; i<PixelCount; i++) 
  {
    strip.SetPixelColor(i, black);
    strip.Show();

    delay(wait);
  }
}

// void rainbow(uint8_t wait) {
//   uint16_t i, j;

//   for(j=0; j<256; j++) {
//     for(i=0; i<PixelCount; i++) {
//       strip.SetPixelColor(i, Wheel((i+j) & 255));
//     }
//     strip.Show();
//     delay(wait);
//   }
// }

// // Slightly different, this makes the rainbow equally distributed throughout
// void rainbowCycle(uint8_t wait) {
//   uint16_t i, j;

//   for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//     for(i=0; i< PixelCount; i++) {
//       strip.SetPixelColor(i, Wheel(((i * 256 / PixelCount) + j) & 255));
//     }
//     strip.Show();
//     delay(wait);
//   }
// }

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < PixelCount; i=i+3) {
        strip.SetPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.Show();

      delay(wait);

      for (uint16_t i=0; i < PixelCount; i=i+3) {
        strip.SetPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// //Theatre-style crawling lights with rainbow effect
// void theaterChaseRainbow(uint8_t wait) {
//   for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
//     for (int q=0; q < 3; q++) {
//       for (uint16_t i=0; i < PixelCount; i=i+3) {
//         strip.SetPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
//       }
//       strip.Show();

//       delay(wait);

//       for (uint16_t i=0; i < PixelCount; i=i+3) {
//         strip.SetPixelColor(i+q, 0);        //turn every third pixel off
//       }
//     }
//   }
// }

// // Input a value 0 to 255 to get a color value.
// // The colours are a transition r - g - b - back to r.
// uint32_t Wheel(byte WheelPos) {
//   WheelPos = 255 - WheelPos;
//   if(WheelPos < 85) {
//     return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//   }
//   if(WheelPos < 170) {
//     WheelPos -= 85;
//     return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//   }
//   WheelPos -= 170;
//   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
// }

