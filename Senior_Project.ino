#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include<SPI.h>
#include <SD.h>
#define SD_ChipSelectPin 4
TMRpcm tmrpcm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tmrpcm.speakerPin=9;
  if(!SD.begin(SD_ChipSelectPin)){
    Serial.println("SD fails");
    return;
  }
  tmrpcm.setVolume(5);
  //play();
}

void play(string audio) {

/*
  initialize SD card here? -- open and read SD
  after SD card is open, search for file
  if file is located, playback the audio
  timeout when complete and return
*/


  tmrpcm.stopPlayback();
  tmrpcm.play(audio);
  //tmrpcm.play("1.wav");
  //delay(240000);
  //tmrpcm.play("2.wav",45);
  //delay(240000);// the time from where the song has to be played.

  delay(100);
  return;
}

void loop() {
  // put your main code here, to run repeatedly:

  string audio[5] = { //initialize as a global
    'audio1.wav',
    'audio2.wav',
    'audio3.wav',
    'audio4.wav',
    'audio5.wav'
  };

  for(int i = 0; i < audio.size(); i++){
    play(audio[i]);
    delay(240000);
  }

  //play();
}