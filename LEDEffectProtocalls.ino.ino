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



  
FastLED.show();
} 

 
