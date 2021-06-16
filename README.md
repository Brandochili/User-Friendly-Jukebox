# User-Friendly-Jukebox
A jukebox aimed at increasing the accessibility of complicated sound systems by simplifying the steps needed to play music.



This jukebox functions by splitting all music into seperate playlists. A user can then press a single button to play their desired playlist. When a button is pressed, the corresponding playlist begins to play and an LED indicator light turns ON to indicate which playlist is being played.

The User-Friendly-Jukebox is being developed while working towards the UN Sustainable Development Goals 3: Good Health & Well-being and 12: Responsible Consumption and Production. 


The User-Friendly-Jukebox code foundation was based on the sources listed below. Brandon Watson expanded on the standard functions of salvadorrueda's YX5300 Demo Code for the purposes of the project. All modifications and additions made by Brandon Watson are clearly indicated in the code and include (the creation of and implimentation of playlists and the shuffle function, the integration of the MCP23017 port expander, and the addition of the Tweaking4All LED code foundation).
   
   The basic opperational foundation of this code was developed from salvadorrueda's demo code for the Serial MP3 Player Catalex (YX5300 chip).
   salvadorrueda's GitHub Page: https://github.com/salvadorrueda/ArduinoSerialMP3Player
   
   LED functionality was developed by Tweaking4All and was used over Adafruit's direct library as it has support for both NeoPixel and FastLED libraries.
   Tweaking4All "Arduino – LEDStrip effects for NeoPixel and FastLED" project page: https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/
