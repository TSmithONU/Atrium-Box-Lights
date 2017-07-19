#include <Conceptinetics.h>


#define DMX_MASTER_CHANNELS 512
#define RXEN_PIN 2

#define RainbowPin 8
#define ManualPin 9

#define RFade A0
#define GFade A1
#define BFade A2

DMX_Master dmx_master(DMX_MASTER_CHANNELS, RXEN_PIN);

const bool christmasMode = false; //False = normal Rainbow mode

void setup() {
  // put your setup code here, to run once:

  dmx_master.enable();

  pinMode(RainbowPin, INPUT_PULLUP);
  pinMode(ManualPin, INPUT_PULLUP);

}

void WriteRGB (int r, int g, int b) {
  for (int i = 1; i <= 512; i += 3) {
    dmx_master.setChannelValue(i, r);
    dmx_master.setChannelValue(i + 1, g);
    dmx_master.setChannelValue(i + 2, b);
  }
}

void ChristmasColors(){

dmx_master.setChannelValue(1, 255);
dmx_master.setChannelValue(2, 0);
dmx_master.setChannelValue(3, 0);

dmx_master.setChannelValue(4, 0);
dmx_master.setChannelValue(5, 127);
dmx_master.setChannelValue(6, 0);

dmx_master.setChannelValue(7, 255);
dmx_master.setChannelValue(8, 0);
dmx_master.setChannelValue(9, 0);

dmx_master.setChannelValue(10, 0);
dmx_master.setChannelValue(11, 127);
dmx_master.setChannelValue(12, 0);

dmx_master.setChannelValue(13, 255);
dmx_master.setChannelValue(14, 0);
dmx_master.setChannelValue(15, 0);

dmx_master.setChannelValue(16, 0);
dmx_master.setChannelValue(17, 127);
dmx_master.setChannelValue(18, 0);

dmx_master.setChannelValue(19, 0);
dmx_master.setChannelValue(20, 127);
dmx_master.setChannelValue(21, 0);

dmx_master.setChannelValue(22, 255);
dmx_master.setChannelValue(23, 0);
dmx_master.setChannelValue(24, 0);

dmx_master.setChannelValue(25, 0);
dmx_master.setChannelValue(26, 127);
dmx_master.setChannelValue(27, 0);

dmx_master.setChannelValue(28, 0);
dmx_master.setChannelValue(29, 127);
dmx_master.setChannelValue(30, 0);

dmx_master.setChannelValue(31, 255);
dmx_master.setChannelValue(32, 0);
dmx_master.setChannelValue(33, 0);

dmx_master.setChannelValue(34, 0);
dmx_master.setChannelValue(35, 127);
dmx_master.setChannelValue(36, 0);

dmx_master.setChannelValue(37, 0);
dmx_master.setChannelValue(38, 127);
dmx_master.setChannelValue(39, 0);

dmx_master.setChannelValue(40, 255);
dmx_master.setChannelValue(41, 0);
dmx_master.setChannelValue(42, 0);

dmx_master.setChannelValue(43, 0);
dmx_master.setChannelValue(44, 127);
dmx_master.setChannelValue(45, 0);

dmx_master.setChannelValue(46, 255);
dmx_master.setChannelValue(47, 0);
dmx_master.setChannelValue(48, 0);

dmx_master.setChannelValue(49, 0);
dmx_master.setChannelValue(50, 127);
dmx_master.setChannelValue(51, 0);

dmx_master.setChannelValue(52, 255);
dmx_master.setChannelValue(53, 0);
dmx_master.setChannelValue(54, 0);

dmx_master.setChannelValue(55, 0);
dmx_master.setChannelValue(56, 127);
dmx_master.setChannelValue(57, 0);

dmx_master.setChannelValue(58, 255);
dmx_master.setChannelValue(59, 0);
dmx_master.setChannelValue(60, 0);

dmx_master.setChannelValue(61, 0);
dmx_master.setChannelValue(62, 127);
dmx_master.setChannelValue(63, 0);

dmx_master.setChannelValue(64, 255);
dmx_master.setChannelValue(65, 0);
dmx_master.setChannelValue(66, 0);

dmx_master.setChannelValue(67, 255);
dmx_master.setChannelValue(68, 0);
dmx_master.setChannelValue(69, 0);

dmx_master.setChannelValue(70, 0);
dmx_master.setChannelValue(71, 127);
dmx_master.setChannelValue(72, 0);

dmx_master.setChannelValue(73, 255);
dmx_master.setChannelValue(74, 0);
dmx_master.setChannelValue(75, 0);

dmx_master.setChannelValue(76, 0);
dmx_master.setChannelValue(77, 127);
dmx_master.setChannelValue(78, 0);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(RainbowPin) == LOW) {
    if (christmasMode == false) {
      int Red = 255;
      int Green = 0;
      int Blue = 0;

      WriteRGB(Red, Green, Blue);
      if (digitalRead(RainbowPin) == LOW) {
        for (int i = 0; i < 255; i++) {
          Red--;
          Green++;
          WriteRGB(Red, Green, Blue);
          delay(50);
          if (digitalRead(RainbowPin) == HIGH) {
            break;
          }
        }

        for (int i = 0; i < 255; i++) {
          Green--;
          Blue++;
          WriteRGB(Red, Green, Blue);
          delay(50);
          if (digitalRead(RainbowPin) == HIGH) {
            break;
          }
        }

        for (int i = 0; i < 255; i++) {
          Blue--;
          Red++;
          WriteRGB(Red, Green, Blue);
          delay(50);
          if (digitalRead(RainbowPin) == HIGH) {
            break;
          }
        }
      }
    }

    if(christmasMode == true){
      ChristmasColors();
    }
  }

  if (digitalRead(ManualPin) == LOW) {
    WriteRGB(map(analogRead(RFade), 0, 1023, 0, 255), map(analogRead(GFade), 0, 1023, 0, 255), map(analogRead(BFade), 0, 1023, 0, 255));



  }

  if (digitalRead(ManualPin) == HIGH && digitalRead(RainbowPin) == HIGH) {
    dmx_master.setChannelRange(1, 512, 0);

  }


}
