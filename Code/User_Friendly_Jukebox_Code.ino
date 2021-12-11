/***********************************************************/
/*
   The following code was developed for the User-Friendly_Jukebox project by Brandon Watson. The code was based on the sources listed below. Brandon Watson added the Tweaking4All code to salvadorrueda's YX5300 Demo Code. All modifications and additions made by Brandon Watson are clearly indicated in the code.
   
   The foundation of this code was developed from salvadorrueda's demo code for the Serial MP3 Player Catalex (YX5300 chip).
   salvadorrueda's GitHub Page: https://github.com/salvadorrueda/ArduinoSerialMP3Player

   LED functions were developed by Tweaking4All which has support for both NeoPixel and FastLED libraries.
   Tweaking4All "Arduino – LEDStrip effects for NeoPixel and FastLED" project page: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
*/
// Demo for the Serial MP3 Player Catalex (YX5300 chip)
// Hardware: Serial MP3 Player *1
// Board:  Arduino UNO
// http://www.dx.com/p/uart-control-serial-mp3-music-player-module-for-arduino-avr-arm-pic-blue-silver-342439#.VfHyobPh5z0
//
//
//


// Uncomment SoftwareSerial for Arduino Uno or Nano.

#include <SoftwareSerial.h>

#define ARDUINO_RX 5  //should connect to TX of the Serial MP3 Player module
#define ARDUINO_TX 6  //connect to RX of the module

#define DEBOUNCE 200  // button debouncer (if using buttons or reed switches)
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 7 //Set how many LEDs are in the strip being used
#define LEDPIN 9 //Set which pin on the Arduino will control the LEDs

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LEDPIN, NEO_GRB + NEO_KHZ800);  //Various settings for the Adafruit NeoPixel library

SoftwareSerial mp3(ARDUINO_RX, ARDUINO_TX);

// Uncomment next line if you are using an Arduino Mega.
//#define mp3 Serial3    // Connect the MP3 Serial Player to the Arduino MEGA Serial3 (14 TX3 -> RX, 15 RX3 -> TX)

static int8_t Send_buf[8] = {0}; // Buffer for Send commands.  // BETTER LOCALLY
static uint8_t ansbuf[10] = {0}; // Buffer for the answers.    // BETTER LOCALLY

String mp3Answer;           // Answer from the MP3.


String sanswer(void);
String sbyte2hex(uint8_t b);


/************ Command byte *************************************************************************/
#define CMD_NEXT_SONG     0X01  // Play next song.
#define CMD_PREV_SONG     0X02  // Play previous song.
#define CMD_PLAY_W_INDEX  0X03
#define CMD_VOLUME_UP     0X04
#define CMD_VOLUME_DOWN   0X05
#define CMD_SET_VOLUME    0X06

#define CMD_SNG_CYCL_PLAY 0X08  // Single Cycle Play.
#define CMD_SEL_DEV       0X09
#define CMD_SLEEP_MODE    0X0A
#define CMD_WAKE_UP       0X0B
#define CMD_RESET         0X0C
#define CMD_PLAY          0X0D
#define CMD_PAUSE         0X0E
#define CMD_PLAY_FOLDER_FILE 0X0F

#define CMD_STOP_PLAY     0X16  // Stop playing continuously. 
#define CMD_FOLDER_CYCLE  0X17
#define CMD_SHUFFLE_PLAY  0x18 //
#define CMD_SET_SNGL_CYCL 0X19 // Set single cycle.
#define CMD_SHUFFLE_FOLDER 0X28
#define CMD_SET_DAC 0X1A
#define DAC_ON  0X00
#define DAC_OFF 0X01

#define CMD_PLAY_W_VOL    0X22
#define CMD_PLAYING_N     0x4C
#define CMD_QUERY_STATUS      0x42
#define CMD_QUERY_VOLUME      0x43
#define CMD_QUERY_FLDR_TRACKS 0x4e
#define CMD_QUERY_TOT_TRACKS  0x48
#define CMD_QUERY_FLDR_COUNT  0x4f

/************ Opitons *****************************************************************************/
#define DEV_TF            0X02


/*************************************************************************************************/
// Lines 91 to 123 were added by Brandon Watson

//Define each button (playlist) variable
const int button1num = 1;
const int button2num = 2;
const int button3num = 3;
const int button4num = 4;
const int button5num = 5;
const int button6num = 6;
const int button7num = 7;
const int button8num = 8;

//Define each button (playlist) and corresponding pins
const int button1pin = (button1num - 1);
const int button2pin = (button2num - 1);
const int button3pin = (button3num - 1);
const int button4pin = (button4num - 1);
const int button5pin = (button5num - 1);
const int button6pin = (button6num - 1);
const int button7pin = (button7num - 1);
const int button8pin = (button8num - 1);

int buttonState1;
int buttonState2;
int buttonState3;
int buttonState4;
int buttonState5;
int buttonState6;
int buttonState7;
int buttonState8;

Adafruit_MCP23017 mcp;

void setup()
{
  Serial.begin(9600);
  mp3.begin(9600);
  delay(500);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  sendCommand(CMD_SEL_DEV, 0, DEV_TF);
  sendCommand(CMD_SET_VOLUME, 0, 20);
  delay(500);

  // Lines 137 to 145 were added by Brandon Watson

  mcp.begin();  // initializes MPC port expansion chip

  for (int x = 0; x < 9; x++)
  {
    mcp.pinMode(x, INPUT); // set pins on mcp chip as inputs
    mcp.pullUp(x, LOW);  // turn on a 100K pullup internally
  }

}


void loop()
{
  // Lines 153 to 215 were added by Brandon Watson

  buttonState1 = mcp.digitalRead(button1pin);
  buttonState2 = mcp.digitalRead(button2pin);
  buttonState3 = mcp.digitalRead(button3pin);
  buttonState4 = mcp.digitalRead(button4pin);
  buttonState5 = mcp.digitalRead(button5pin);
  buttonState6 = mcp.digitalRead(button6pin);
  buttonState7 = mcp.digitalRead(button7pin);
  buttonState8 = mcp.digitalRead(button8pin);



  if (buttonState1 == 1)
  {
    sendCommand(CMD_FOLDER_CYCLE, 1, 0);
    //setPixel(0, 0, 0, 50);
    ledCall(0);
  }

  if (buttonState2 == 1)
  {
    sendCommand(CMD_FOLDER_CYCLE, 2, 0);
    //setPixel(1, 0, 50, 0);
    ledCall(1);
  }

  if (buttonState3 == 1)
  {
    sendCommand(CMD_FOLDER_CYCLE, 3, 0);
    //setPixel(2, 50, 0, 0);
    ledCall(2);
  }

  if (buttonState4 == 1)
  {
    sendCommand(CMD_FOLDER_CYCLE, 4, 0);
    //setPixel(3, 30, 10, 10);
    ledCall(3);
  }

  if (buttonState5 == 1)
  {
    sendCommand(CMD_FOLDER_CYCLE, 5, 0);
    //setPixel(4, 25, 0, 25);
    ledCall(4);
  }

  if (buttonState6 == 1)
  {
    sendCommand(CMD_FOLDER_CYCLE, 6, 0);
    //setPixel(5, 0, 25, 25);
    ledCall(5);
  }

  if (buttonState7 == 1)
  {
    sendCommand(CMD_SHUFFLE_PLAY, 0, 1);
    //setPixel(6, 0, 200, 70);
    ledCall(6);
  }

  delay(50);

  /*
    // Check for the answer.
    if (mp3.available())
    {
      Serial.println(decodeMP3Answer());
    }
    delay(100);
  */
}


/********************************************************************************/
/*Function decodeMP3Answer: Decode MP3 answer.                                  */
/*Parameter:-void                                                               */
/*Return: The                                                  */

String decodeMP3Answer() {
  String decodedMP3Answer = "";

  decodedMP3Answer += sanswer();

  switch (ansbuf[3]) {
    case 0x3A:
      decodedMP3Answer += " -> Memory card inserted.";
      break;

    case 0x3D:
      decodedMP3Answer += " -> Completed play num " + String(ansbuf[6], DEC);
      break;

    case 0x40:
      decodedMP3Answer += " -> Error";
      break;

    case 0x41:
      decodedMP3Answer += " -> Data recived correctly. ";
      break;

    case 0x42:
      decodedMP3Answer += " -> Status playing: " + String(ansbuf[6], DEC);
      break;

    case 0x48:
      decodedMP3Answer += " -> File count: " + String(ansbuf[6], DEC);
      break;

    case 0x4C:
      decodedMP3Answer += " -> Playing: " + String(ansbuf[6], DEC);
      break;

    case 0x4E:
      decodedMP3Answer += " -> Folder file count: " + String(ansbuf[6], DEC);
      break;

    case 0x4F:
      decodedMP3Answer += " -> Folder count: " + String(ansbuf[6], DEC);
      break;
  }

  return decodedMP3Answer;
}






/********************************************************************************/
/*Function: Send command to the MP3                                             */
/*Parameter: byte command                                                       */
/*Parameter: byte dat1 parameter for the command                                */
/*Parameter: byte dat2 parameter for the command                                */

void sendCommand(byte command) {
  sendCommand(command, 0, 0);
}

void sendCommand(byte command, byte dat1, byte dat2) {
  delay(20);
  Send_buf[0] = 0x7E;    //
  Send_buf[1] = 0xFF;    //
  Send_buf[2] = 0x06;    // Len
  Send_buf[3] = command; //
  Send_buf[4] = 0x01;    // 0x00 NO, 0x01 feedback
  Send_buf[5] = dat1;    // datah
  Send_buf[6] = dat2;    // datal
  Send_buf[7] = 0xEF;    //
  Serial.print("Sending: ");
  for (uint8_t i = 0; i < 8; i++)
  {
    mp3.write(Send_buf[i]) ;
    Serial.print(sbyte2hex(Send_buf[i]));
  }
  Serial.println();
}



/********************************************************************************/
/*Function: sbyte2hex. Returns a byte data in HEX format.                       */
/*Parameter:- uint8_t b. Byte to convert to HEX.                                */
/*Return: String                                                                */


String sbyte2hex(uint8_t b)
{
  String shex;

  shex = "0X";

  if (b < 16) shex += "0";
  shex += String(b, HEX);
  shex += " ";
  return shex;
}


/********************************************************************************/
/*Function: shex2int. Returns a int from an HEX string.                         */
/*Parameter: s. char *s to convert to HEX.                                      */
/*Parameter: n. char *s' length.                                                */
/*Return: int                                                                   */

int shex2int(char *s, int n) {
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      r *= 16;
      r += s[i] - '0';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      r *= 16;
      r += (s[i] - 'A') + 10;
    }
  }
  return r;
}


/********************************************************************************/
/*Function: sanswer. Returns a String answer from mp3 UART module.          */
/*Parameter:- uint8_t b. void.                                                  */
/*Return: String. If the answer is well formated answer.                        */

String sanswer(void)
{
  uint8_t i = 0;
  String mp3answer = "";

  // Get only 10 Bytes
  while (mp3.available() && (i < 10))
  {
    uint8_t b = mp3.read();
    ansbuf[i] = b;
    i++;

    mp3answer += sbyte2hex(b);
  }

  // if the answer format is correct.
  if ((ansbuf[0] == 0x7E) && (ansbuf[9] == 0xEF))
  {
    return mp3answer;
  }

  return "???: " + mp3answer;
}

/**********************************************************************************/
// Lines 384 to 469 were added by Brandon Watson

// neoPixel function that sets all LED's to the colour profile sent to it
void ledCall(int ledButton) {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  if (ledButton == 0)
  {
    setPixel(0, 0, 0, 50);
    setPixel(1, 0, 0, 0);
    setPixel(2, 0, 0, 0);
    setPixel(3, 0, 0, 0);
    setPixel(4, 0, 0, 0);
    setPixel(5, 0, 0, 0);
    setPixel(6, 0, 0, 0);
  }

  if (ledButton == 1)
  {
    setPixel(1, 0, 50, 0);
    setPixel(0, 0, 0, 0);
    setPixel(2, 0, 0, 0);
    setPixel(3, 0, 0, 0);
    setPixel(4, 0, 0, 0);
    setPixel(5, 0, 0, 0);
    setPixel(6, 0, 0, 0);
  }

  if (ledButton == 2)
  {
    setPixel(2, 50, 0, 0);
    setPixel(0, 0, 0, 0);
    setPixel(1, 0, 0, 0);
    setPixel(3, 0, 0, 0);
    setPixel(4, 0, 0, 0);
    setPixel(5, 0, 0, 0);
    setPixel(6, 0, 0, 0);
  }

  if (ledButton == 3)
  {
    setPixel(3, 30, 10, 10);
    setPixel(0, 0, 0, 0);
    setPixel(1, 0, 0, 0);
    setPixel(2, 0, 0, 0);
    setPixel(4, 0, 0, 0);
    setPixel(5, 0, 0, 0);
    setPixel(6, 0, 0, 0);
  }

  if (ledButton == 4)
  {
    setPixel(4, 25, 0, 25);
    setPixel(0, 0, 0, 0);
    setPixel(1, 0, 0, 0);
    setPixel(2, 0, 0, 0);
    setPixel(3, 0, 0, 0);
    setPixel(5, 0, 0, 0);
    setPixel(6, 0, 0, 0);
  }

  if (ledButton == 5)
  {
    setPixel(5, 0, 25, 25);
    setPixel(0, 0, 0, 0);
    setPixel(1, 0, 0, 0);
    setPixel(2, 0, 0, 0);
    setPixel(3, 0, 0, 0);
    setPixel(4, 0, 0, 0);
    setPixel(6, 0, 0, 0);
  }

  if (ledButton == 6)
  {
    setPixel(6, 0, 200, 70);
    setPixel(0, 0, 0, 0);
    setPixel(1, 0, 0, 0);
    setPixel(2, 0, 0, 0);
    setPixel(3, 0, 0, 0);
    setPixel(4, 0, 0, 0);
    setPixel(5, 0, 0, 0);
  }
}

/***********************************************************************************************************/

void showStrip() {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
}


void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  Serial.println("LED void function test");
  showStrip();
}

/************************************************************************************************************/
