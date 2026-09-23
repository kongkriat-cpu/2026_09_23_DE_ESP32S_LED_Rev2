#include "main.h"

/***********************************************************************************/
// Function: setup
// Description: This function runs once when the microcontroller is powered on or reset.
// It initializes the serial communication, sets the pin modes for the LED pins, and ensures that
// all LEDs are turned off initially.
/***********************************************************************************/
void setup()
{
 Serial.begin(115200); // Initialize serial communication at 115200 baud rate

 pinMode(LED_PIN_BLINK, OUTPUT); // Define the LED pin as an output

 pinMode(LED_PIN_RED, OUTPUT); // Define the RED LED pin as an output
 pinMode(LED_PIN_GREEN, OUTPUT); // Define the GREEN LED pin as an output
 pinMode(LED_PIN_BLUE, OUTPUT); // Define the BLUE LED pin as an output

 digitalWrite(LED_PIN_BLINK, LOW); // Ensure the LED is off initially

 digitalWrite(LED_PIN_RED, LOW); // Ensure the RED LED is off initially
 digitalWrite(LED_PIN_GREEN, LOW); // Ensure the GREEN LED is off initially
 digitalWrite(LED_PIN_BLUE, LOW); // Ensure the BLUE LED is off initially

}
/***********************************************************************************/
// Function: loop
// Description: This function runs repeatedly after the setup() function.
// It calls the blink_led function and sets the RGB LED to RED, GREEN, and BLUE colors with a delay of 500 milliseconds between each color change.
/***********************************************************************************/
void loop()
{
 blink_led(); // Call the blink_led function

 rgb_led(HIGH, LOW, LOW); // Set the RGB LED to RED
 delay(500); // Wait for 1 second

 rgb_led(LOW, HIGH, LOW); // Set the RGB LED to GREEN
 delay(500); // Wait for 1 second

 rgb_led(LOW, LOW, HIGH); // Set the RGB LED to BLUE
 delay(500); // Wait for 1 second

 rgb_led(LOW, HIGH, HIGH); // Set the RGB LED to BLUE
 delay(500); // Wait for 1 second

 rgb_led(HIGH, HIGH, LOW); // Set the RGB LED to BLUE
 delay(500); // Wait for 1 second
}

/***********************************************************************************/
// Function: blink_led
// Description: This function blinks the LED connected to the defined pin.
// It turns the LED on for 500 milliseconds, then turns it off for 500 milliseconds.
// It also prints the LED pin number to the serial monitor. 
/***********************************************************************************/
int blink_led(void) 
{
 // Blink the LED on and off with a delay
 digitalWrite(LED_PIN_BLINK, HIGH); // Turn the LED on
 delay(500); // Wait for 500 milliseconds
 digitalWrite(LED_PIN_BLINK, LOW); // Turn the LED off
 delay(500); // Wait for 500 milliseconds

 Serial.println("Blinking LED on pin " + String(LED_PIN_BLINK)); // Print the LED pin number to the serial monitor
 Serial.flush(); // Ensure the message is sent immediately

 return 0; // Return success
}

/***********************************************************************************/
// Function: rgb_led
// Description: This function sets the color of an RGB LED based on the provided red, green
// and blue values. Each value should be either HIGH (1) or LOW (0).
/***********************************************************************************/
int rgb_led(int red, int green, int blue)
{
 // Set the RGB LED color based on the provided values
 digitalWrite(LED_PIN_RED, red); // Set the RED LED pin
 digitalWrite(LED_PIN_GREEN, green); // Set the GREEN LED pin
 digitalWrite(LED_PIN_BLUE, blue); // Set the BLUE LED pin

 Serial.println("RGB LED set to R:" + String(red) + " G:" + String(green) + " B:" + String(blue)); // Print the RGB values to the serial monitor
 Serial.flush(); // Ensure the message is sent immediately

 return 0; // Return success
}