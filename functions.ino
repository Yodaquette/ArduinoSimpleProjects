/*
  Andrew Goodman
  January 27, 2016

  Practice implementing:
  - variable declaration and assignment
  - calculations
  - conditionals
  - iteration
  - use of functions
  - printing to the console
*/
#include "TimeLib.h"

// Onboard LED
int pin = 13;

/*
	Blink the onboard LED as much as possible for 5 seconds

	@param : pin
	- The pin number of the LED to power

	@param : sleep
	- The amount of time to delay between LED blinks

	Returns : The number of blinks over 5 seconds for the given delay time period
*/
int blinker(int pin,float sleep)
{
	int blinkCount = 0;
	time_t t = now();

	// Blink for 5 seconds
	while(now() - t < 5)
	{
		digitalWrite(pin,HIGH);
		delay(sleep);
		digitalWrite(pin,LOW);
		delay(sleep);

		blinkCount++;
	}
	
	return blinkCount;
}
 /*
 	Run the blinker function sequentially reducing the delay time period between runs.
 	Between each run of the blinker function, print the BlinkSet number and the number of
 	blinks per set. The number of blinks per set should increase with each run.

 	@para : sleep
 	- The time period between LED blinks.

 	@param : sleepAugmenter
 	- A percentage by which the delay time period will be reduced.
 */
int blinkRunner(float sleep = 1000.0,float sleepAugmenter = 0.25)
{
	int blinkSet = 1;
	int blinks = 0;
	Serial.begin(9600);

	// Iterate until the delay time is less than 1/10 of a second
	while(sleep > 100)
	{
		// Store the number of blinks
		blinks = blinker(pin,sleep);
		
		// Reduce the delay time period
		sleep -= (sleep * sleepAugmenter);

		// Print report
		Serial.print("Number of blinks for BlinkSet ");
		Serial.print(blinkSet);
		Serial.print(": ");
		Serial.print(blinks);
		Serial.print("\n");
		
		blinkSet++;
	}
	
	return 0;
}

//****************begin standard functions****************
void setup()
{
	// Set onboard LED pin number to output
	pinMode(pin,OUTPUT);
}

void loop()
{
	// Run the blink program
	blinkRunner();
}
//****************end standard functions****************
