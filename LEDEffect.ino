#include <FastLED.h>
#define LED_DT 6
#define NUM_LEDS 60
#define COLOR_ORDER  GRB
#define LED_TYPE WS2812B

int beats_per_minute = 16;


uint8_t min = 0;
uint8_t max = 255;
uint16_t gHue = 0;

uint8_t max_bright = 200;
struct CRGB leds[NUM_LEDS];

byte red1 = 255;
byte green1 = 255;
byte blue1 = 255;
byte red2 = 255;
byte green2 = 255;
byte blue2 = 255;
byte red3 = 100;
byte green3 = 100;
byte blue3 = 100;
byte brightness = 196;



void setup() {
 LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);
 FastLED.setBrightness(max_bright);
 FastLED.show();
 FastLED.clear();
}


void loop() {
FastLED.clear();


//int pos1a = beatsin16( 16, 0, NUM_LEDS);
//int pos1b = beatsin16( 16, 6+0, 21);
//int pos1c = beatsin16( 15, 0, 60);
//
//leds[0+pos1a] = CRGB(red1, green1, blue1);
//leds[0+pos1c] = CRGB(red1, green1, blue1);
//leds[NUM_LEDS-pos1a] = CRGB(red2, green2, blue2);

meteorRain(0xff,0xff,0xff,10, 64, true, 30);

  
FastLED.show();
} 

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13,0,NUM_LEDS);
  leds[pos] += CHSV( gHue, 255, 192);
}
void meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {  
  
 
  for(int i = 0; i < NUM_LEDS+NUM_LEDS; i++) {
   
   
    // fade brightness all LEDs one step
    for(int j=0; j<NUM_LEDS; j++) {
      if( (!meteorRandomDecay) || (random(10)>5) ) {
        fadeToBlack(j, meteorTrailDecay );        
      }
    }
   
    // draw meteor
    for(int j = 0; j < meteorSize; j++) {
      if( ( i-j <NUM_LEDS) && (i-j>=0) ) {
        CRGB.setLED(i-j, red, green, blue);
      }
    }
   
    showStrip();
    delay(SpeedDelay);
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
    // NeoPixel
    uint32_t oldColor;
    uint8_t r, g, b;
    int value;
   
    oldColor = strip.getPixelColor(ledNo);
    r = (oldColor & 0x00ff0000UL) >> 16;
    g = (oldColor & 0x0000ff00UL) >> 8;
    b = (oldColor & 0x000000ffUL);

    r=(r<=10)? 0 : (int) r-(r*fadeValue/256);
    g=(g<=10)? 0 : (int) g-(g*fadeValue/256);
    b=(b<=10)? 0 : (int) b-(b*fadeValue/256);
   
    strip.setPixelColor(ledNo, r,g,b);
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[ledNo].fadeToBlackBy( fadeValue );
 #endif  
}
 
