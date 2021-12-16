# User-Friendly-Jukebox
A jukebox aimed at increasing the accessibility of complicated sound systems by simplifying the steps needed to play music.

User-Friendly-Jukebox Commercial Link: https://www.youtube.com/watch?v=B-ChZFBF7p4

This jukebox functions by splitting all music into seperate playlists. A user can then press a single button to play their desired playlist. When a button is pressed, the corresponding playlist begins to play and an LED indicator light turns ON to indicate which playlist is being played.

The User-Friendly-Jukebox is being developed while working towards the UN Sustainable Development Goals 3: Good Health & Well-being and 12: Responsible Consumption and Production. 


The User-Friendly-Jukebox code foundation was based on the sources listed below. Brandon Watson expanded on the standard functions of salvadorrueda's YX5300 Demo Code for the purposes of the project. All modifications and additions made by Brandon Watson are clearly indicated in the code and include (the creation of and implimentation of playlists and the shuffle function, the integration of the MCP23017 port expander, and the addition of the Tweaking4All LED code foundation).
   
   
User-Friendly-Jukebox Build Process

Step 1: Introductions Points
To start the project off, you will need to plan out the space where the User-Friendly-Jukebox will be set up. Does the clubhouse currently have a sound system? If so, then the Jukebox can simply be plugged into the existing sound system. If not, you will need to get some speakers to play the sound coming from the Jukebox. The speakers do not have to be expensive, however, they will need to have an amp built-in as the User-Friendly-Jukebox does not have the capability to power speakers on its own. Think of it like a phone or an iPod/mp3 player. An inexpensive set of computer speakers would be a great option as they are simple to set up, come with all the components needed to make the connection and their sound can easily fill the smaller areas commonly found in lawn bowling clubhouses with music for background and dancing. I am including some links to a few different computer speaker options that would work in different price ranges.
•	AmazonBasicsComputerSpeakers
•	Logitech z533 2.1 Channel Speaker System
If you have an existing sound system, you will want to make sure that it has either an XLR out, analog out or 3.5mm AUX out. XLR connections are commonly found on microphones while analog connections are the red/white cables commonly found on home stereo systems. The User Friendly Jukebox uses a 3.5mm AUX connection. Adapter cables can easily be found on Amazon.ca to go from either a XLR or analog to 3.5mm AUX. I am including these cables below.
•	XLR to 3.5mm AUX
•	Analog to 3.5mm AUX
•	3.5mm AUX to 3.5mm AUX
Once you have a place in the clubhouse for the Jukebox and a speaker system to connect to it, you can move on to sourcing the parts to build it.

Step 2: Sourcing the Parts
One of the included files for this project is a bill of materials. The bill of materials is a list of all electronic components used to build the User-Friendly-Jukebox. All of these components can be purchased on Amazon.ca. However, other websites to look for components include Sparkfun.com, Adafruit.com, and BuyaPi.ca. I would recommend using an Arduino Uno for this build. Its larger size will make connecting it to the other components slightly easier than smaller Arduino boards such as the Arduino Nano Every. Note that either an official Arduino or unofficial Arduino can be used for this project.

Step 3: Wood Working Component
The wood working component of the User-Friendly-Jukebox build can be as simple or complicated as desired. The ‘box’ for the Jukebox only serves the purpose of mounting the buttons for use and safely concealing all electronics and protecting them from outside elements such as static. If one of the members of your club is a wood worker who is interested in building a fancy jukebox, then great! However, the jukebox can very easily be made out of a simple wooden box or crate or even a plastic bin. The box can be painted or decorated in an endless number of ways. Additionally, the jukebox electronics can be mounted inside of a cabinet with the buttons being accessible from outside the cabinet. There really are an endless number of ways to install the jukebox to match any number of skill sets. The Jukebox I designed for this project was made out of walnut. The curved top was created by making a series or repeated angle cuts on the table saw which gave 24 of the same pieces. Because the pieces all had a very slight angle cut, when glued together, they naturally form an arc. Once the glue had dried, I used a sander to smooth out the slight ridges that were left where the pieces were glued together. The base (tabletop) of the jukebox was made out of a butcher block which is a pre-finished countertop that can be purchased at stores such as Home Depot, Lowes or Rona. I designed a 3D printable back panel for mounting the electronic components of the Jukebox. This back panel has built-in access points for powering and coding the Arduino, access to the micro SD card to make adding music easy and a 3.5mm port to connect it to speakers. The 3D printable file is included for this project and can be printed on most 3D printers. The back panel is mounted to the jukebox with eight screws. If your club does not have direct access to a 3D printer, there are many online 3D printing solutions available. They will 3D print the file and ship it to you at a fair price. I am including a link below to a well-established 3D printing service in Canada.
•	3D Printing Canada
There are also many local people who may be offering 3D printing services. Check websites such as Varagesale or Kijiji for ads for local 3D printing services. A similar panel can also be made from a piece of wood such as ¼ inch thick plywood.

Step 4: Loading the Code & Arduino Setup
To get the Arduino ready to control the Jukebox, the code included in this project must first be uploaded to it. To do this, you have to install the Arduino IDE software which can be found at Arduino.cc. Once installed, you can plug your Arduino into your computer using a USB cable and launch the Arduino IDE software. Open the code included in this project by downloading it to your computer and opening it in Arduino IDE. Next, make sure your Arduino is selected in Arduino IDE by going to ‘Tools’ – ‘Port’ and selecting the port that shows your Arduino. The code can be uploaded and the Arduino is now ready. Once the code has been uploaded to the Arduino, open the serial monitor to make sure that the Arduino is communicating as it should. There should be no error messages. 

Step 5: Loading Your Music
Take a micro SD card and plug it into your computer to upload your music files to it. For this project, I recommend using MP3 files as they take up less space on the micro SD card and seem to work the best with the serial MP3 players. The files and folders must be named in a specific way so that the Serial MP3 player can find them. Name folders as ‘01’, ‘02’, ‘03’, etc. and name songs within the folders as ‘001.mp3’, ‘002.mp3’, etc. Currently (as of December 7, 2021), the Jukebox Arduino code is set up to control up to six playlists with a general shuffle function. This will be updated in the future to support up to 12 playlists.

Step 6: Soldering Connections
Whenever work is being done on the circuit, make sure to have the Arduino and all other components disconnected from any computer or power source to avoid damaging any of the components. Also, avoid using a vacuum or dusting any of the components as this can build up static electricity which can damage the electrical components. For best results, it is best to solder all of the connections so that they stay in place over time. However, if your club does not have a member who is comfortable soldering, all of the connections can be made using crimp connections that can be purchased from Amazon.ca. Alternatively, connections can be made instead with a breadboard. Using a breadboard, the wires and board connections are not soldered but held in place with friction. This is generally used for troubleshooting or experimenting but once, mounted inside the Jukebox, all connections should stay in place. If you decide to go with the breadboard option, make sure that you buy an Arduino board that has the header pins already soldered on so that it can simply be pushed into the breadboard. Below is a list of suitable wires, breadboards and Arduinos that can be used with a non-soldered method.
•	Arduino
•	Wires
•	Breadboard 
This project includes a detailed schematic for all electrical connections. Begin making the connections as illustrated in the included schematic paying close attention to make sure that you are working with the correct pins. It is a good idea to test the code as you make connections. For example, I would connect the Arduino, Serial MP3 player, and MCP Port Expander Chip together. Then plug the Arduino into a computer and run the code. Check the serial window to make sure that the Arduino and Serial MP3 player are talking without errors. Then, unplug the Arduino from the computer and connect the first button and first LED. Plug the Arduino back in and test the button. The music from your first playlist should play and the LED should light up (make sure you have the micro SD card plugged into the serial MP3 player with music files on it before powering up the Arduino). Do this for each button and LED to help with troubleshooting issues. As each button corresponds with a certain folder on the micro SD card, if you only have one folder or you aren’t using folders, only one button will be needed.

Step 7: Mounting the Electronics Inside the Box
Once the electrical connections have been made and the jukebox is working correctly, you can install the electrical components inside the box or shell of the jukebox. Screws or hot glue can be used to fasten the components to the jukebox. Make sure not to damage the boards with the hot glue or screws when fastening them.

   The basic opperational foundation of this code was developed from salvadorrueda's demo code for the Serial MP3 Player Catalex (YX5300 chip).
   salvadorrueda's GitHub Page: https://github.com/salvadorrueda/ArduinoSerialMP3Player
   
   LED functionality was developed by Tweaking4All and was used over Adafruit's direct library as it has support for both NeoPixel and FastLED libraries.
   Tweaking4All "Arduino – LEDStrip effects for NeoPixel and FastLED" project page: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
