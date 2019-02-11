#include <LedControl.h>

LedControl lc=LedControl(12,10,11,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delay_time=500;  // Delay between Frames

// Put values in arrays
// Forth frame, first letter
byte letter1a[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};

// Fourth frame, second letter
byte letter1b[] =
{
   B11000011, 
   B11000011,
   B11000011,
   B11111111,
   B11111111,
   B11000011,
   B11000011,
   B11000011
};

// Third frame, first letter
byte letter2a[] =
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00100000,
  B01000000,
  B10000000
};

// Third frame, second letter
byte letter2b[] =
{
  B11111111,
  B11111111,
  B11000000,
  B11000000,
  B11000000,
  B11000000,
  B11111111,
  B11111111
};

// Second frame, first letter
byte letter3a[] = 
{
   B11111111,  
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B11111111
};

// Second frame, second letter
byte letter3b[] =
{
  B11111111,
  B11111111,
  B11000000,
  B11110000,
  B11110000,
  B11000000,
  B11111111,
  B11111111
};


// First frame, second letter
byte letter4b[] =
{
   B11111111, 
   B11111111,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000
};

// First frame, first letter
byte letter4a[] =
{
   B11000011, 
   B11000011,
   B11000011,
   B11111111,
   B11111111,
   B11000011,
   B11000011,
   B11000011
};

byte letter00[] =
{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};
void setup()
{
  for (int i = 0; i < 4; i++) 
  {
    lc.shutdown(i,false); 
    lc.setIntensity(i,5);
    lc.clearDisplay(i);
  }
}

void draw_letter(int n, byte letter_array[])
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(n, i, letter_array[i]);
  }
}

void loop(){  
   // Paint "HI"
  draw_letter(3, letter4a);
  draw_letter(2, letter3a);
  draw_letter(1, letter2a);
  draw_letter(0, letter1a);
  // Pause
  delay(delay_time);

  // Clear Screen
  draw_letter(0, letter00);
  draw_letter(1, letter00);
  draw_letter(2, letter00);
  draw_letter(3, letter00);
  delay(delay_time);

  // Paint "TECH"
  draw_letter(3, letter4b);
  draw_letter(2, letter3b);
  draw_letter(1, letter2b);
  draw_letter(0, letter1b);
  delay(delay_time);

  // Clear Screen
  draw_letter(0, letter00);
  draw_letter(1, letter00);
  draw_letter(2, letter00);
  draw_letter(3, letter00);
  delay(delay_time);
  
}
