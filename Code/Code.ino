#include <Adafruit_GFX.h>    
#include <Adafruit_ST7789.h> 
#include <SPI.h>
#include "images.h" // အနောက်ခန်းက images.h ကို လှမ်းချိတ်ခြင်း

// ESP32-C3 Hardware SPI Pin အထိုင်များ
#define TFT_CS         5   
#define TFT_RST        1   
#define TFT_DC         7   
#define TFT_MOSI       6   
#define TFT_SCLK       4   

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  // 1.54" ST7789 Display အား SPI 40MHz နှုန်းဖြင့် စတင်နှိုးခြင်း
  tft.init(240, 240, 40000000); 
  tft.setRotation(1); 
  tft.fillScreen(ST77XX_BLACK); // အစောဆုံး စခရင်အား အမည်းရောင်ချပြပစ်မည်

  // 🔄 Direct Buffer စနစ်ဖြင့် ပုံဆွဲရန် စတင်ခြင်း
  tft.startWrite();
  tft.setAddrWindow(0, 0, 240, 240);
  
  // FileToCArray မှရလာသော 16-bit array အား စခရင်ပေါ်သို့ တိုက်ရိုက်တွန်းတင်ခြင်း
  tft.writePixels((uint16_t*)image_01, 240 * 240);
  
  tft.endWrite();
}

void loop() {
  // တစ်ပုံတည်းမောင်းနှင်ခြင်းဖြစ်၍ void loop ထဲတွင် ငြိမ်နေမည်ဖြစ်သည်
}
