#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SPI.h>
#include <SD.h>
#include <iostream>
#include <list>
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;

using namespace std;

File root;

list<string> mylist;

// string audio[5] = { //initialize as a global
//   "audio1.wav",
//   'audio2.wav',
//   'audio3.wav',
//   'audio4.wav',
//   'audio5.wav'
// };

void setup() {
  // This code is to setup the program and verify if the SD pin is read correctly
  Serial.begin(9600);
  while (!Serial) {
  ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");

  tmrpcm.speakerPin=9;
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println("initialization failed. Things to check:");

    Serial.println("1. is a card inserted?");

    Serial.println("2. is your wiring correct?");

    Serial.println("3. did you change the chipSelect pin to match your shield or module?");

    Serial.println("Note: press reset or reopen this serial monitor after fixing your issue!");

    while (true);
  }
  Serial.println("initialization done.");
  root = SD.open("/");
  tmrpcm.setVolume(5);

  /*
    initialize SD card here? -- open and read SD
    after SD card is open, search for file
    if file is located, playback the audio
    timeout when complete and return
  */
  while (true) {
    File entry =  root.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    
    mylist.push_back(entry.name());
    entry.close();
  }
}

void play() {
  string fileName;
  tmrpcm.stopPlayback();
  for (it = mylist.begin(); it != mylist.end(); it++)
  {
    // Access the object through iterator
    fileName = it;
    tmrpcm.play(fileName);    //file name has to be in wav format
    delay(3000);
  }
  return;
}

void loop() {
  play();
}



