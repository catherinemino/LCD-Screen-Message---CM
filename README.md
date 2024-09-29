# LCD-Screen-Message---CM
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define I2C_ADDR 0x27 // Common I2C address for 16x2 LCD
#define LCD_WIDTH 16
#define LCD_HEIGHT 2


LiquidCrystal_I2C lcd(I2C_ADDR, LCD_WIDTH, LCD_HEIGHT);


// Message to display
const char* message1 = "I love";
const char* message2 = "Engineering!";


void setup() {
 lcd.init(); // Initialize the LCD
 lcd.backlight(); // Turn on the backlight
}


void loop() {
 dissolveText(message1, message2); // Continuously dissolve the text
}


// Function to create a dissolve effect
void dissolveText(const char* text1, const char* text2) {
 int len1 = strlen(text1);
 int len2 = strlen(text2);
  // Gradually reveal the first line
 for (int i = 0; i <= len1; i++) {
   lcd.clear();
   lcd.setCursor(0, 0);
  
   // Print the first i characters of the first line
   for (int j = 0; j < i; j++) {
     lcd.print(text1[j]);
   }
  
   // Print the second line fully
   lcd.setCursor(0, 1);
   lcd.print(text2);
  
   delay(300); // Adjust the speed of the dissolve effect
 }}
