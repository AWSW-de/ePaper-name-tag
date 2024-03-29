// ###################################################################################################################################################
// #
// # Code for "ePaper name tag" project: https://www.printables.com/de/model/224225-epaper-name-tag
// #
// # Code by https://github.com/AWSW-de 
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/ePaper-name-tag/blob/main/LICENSE
// #
// ###################################################################################################################################################

// ###################################################################################################################################################
// #
// # Code version:
// #
// ###################################################################################################################################################
// V1.0.1 
// ###################################################################################################################################################
// Change text here: 
String Line1 = "Hello! I am:";
String Line2 = "Your Name Here";
// NOTE: No changes needed from this line on
// ###################################################################################################################################################
// ePaper display and fonts:
#include <GxEPD.h>                        // Install library "GxEPD" plus its named addons and restart Ardunino --> https://github.com/ZinggJM/GxEPD
#include <GxGDEH029A1/GxGDEH029A1.h>      // 2.9" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
// ###################################################################################################################################################
void setup() {
  Serial.begin(115200);
  display.init();
  delay(1000);
  String DisplayText = "-";
  DisplayText = Line1 + "\n\n" + Line2;
  showFont(DisplayText);
}
// ###################################################################################################################################################
void loop() {
  // not used
}
// ###################################################################################################################################################
// Write text to the display:
void showFont(String text)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setRotation(3);
  display.setCursor(0, 0);
  display.setFont(&FreeMonoBold18pt7b);
  display.println();
  display.println(text);
  display.update();
}
