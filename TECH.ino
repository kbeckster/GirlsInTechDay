#include <LedControl.h>

LedControl lc=LedControl(12,10,11,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames

// Put values in arrays
byte letter1[] =
{
   B11000011,  // Fourth frame
   B11000011,
   B11000011,
   B11111111,
   B11111111,
   B11000011,
   B11000011,
   B11000011
};

byte letter2[] =
{
  B11111111, // Third frame
  B11111111,
  B11000000,
  B11000000,
  B11000000,
  B11000000,
  B11111111,
  B11111111
};

byte letter3[] =
{
  B11111111, // Second frame
  B11111111,
  B11000000,
  B11110000,
  B11110000,
  B11000000,
  B11111111,
  B11111111
};

byte letter4[] =
{
   B11111111,  // First frame
   B11111111,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000
};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);  // Wake up displays
  lc.shutdown(3,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);  // Set intensity levels
  lc.setIntensity(3,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
}


//  Take values in Arrays and Display them
void sletter1()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,letter1[i]);
  }
}

void sletter2()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,letter2[i]);
  }
}

void sletter3()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(2,i,letter3[i]);
  }
}

void sletter4()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,letter4[i]);
  }
}

void loop(){
  sletter1();
  sletter2();
  sletter3();
  sletter4();
}
