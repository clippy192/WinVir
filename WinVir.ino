#include <Mouse.h>
#include <Keyboard.h>

long randomdelay;
//long mousedelay;
//int mousemove;
int picker;
float ms;
float mins;
long secs;
int mousex;
int mousey;
int mousect;
int tabret;

String stringOne = "m: Next boi is in ";
String stringTwo = "s. Picker is at ";
String stringThree = "/60, so it'll be a ";
String stringFour = "Annoyance is at ";

// how annoying you want this script to be, lower is more annoying. recommended between 1 and 5
int annoyance = 1                   ;

void setup() {
  Keyboard.begin(); //start emulating mouse
  Mouse.begin(); //start emulating keyboard
  delay(10000);
  Serial.begin(9600);
  Serial.print(stringFour);
  Serial.println(annoyance);
}

void loop() {

  //initial seed and starting values for shit modified by annoyance factor
  randomSeed(analogRead(3));
  randomdelay = random(5000, 30000); //delay between each annoyance method
  //mousedelay = random(100, 2000); //delay between each individual mouse movement in method 6
  //mousemove = random(10, 100); //how many times to actually move the mouse

  ms = millis(); //keeps track of how long the script has been running
  mins = ms / 60000;
  picker = random(1, 50); //used to choose which method to annoy the user with.
  tabret = random(1, 16); //used to press tab a certain amount of times in method 5

  randomdelay = annoyance * randomdelay;
  //mousedelay = annoyance * mousedelay;
  //mousemove = mousemove / annoyance;

  secs = randomdelay / 1000;

  //these next few lines are used for debugging.
  String displayString = mins + stringOne + secs + stringTwo + picker + stringThree;
  Serial.print(displayString);
  if (picker < 10) Serial.println("spaceboi.");
  else if (picker < 20) Serial.println("backboi.");
  else if (picker < 30) Serial.println("altboi.");
  else if (picker < 40) Serial.println("winboi.");
  else if (picker < 50) {
    Serial.print("tab-boi. should press tab this many times: ");
    Serial.println(tabret);
  }
  else Serial.println("mouseboi.");

  delay(randomdelay); //delays the time set above before pressing a key

  if (picker < 10) { //if picker is under 10, spacebar.
    Keyboard.write(' ');
  }
  else if (picker < 20) { //if picker is under 20, backspace.
    Keyboard.write(KEY_BACKSPACE);
  }
  else if (picker < 30) { //if picker is under 30, alt-tab.
    Keyboard.press(KEY_LEFT_ALT);
    delay(100);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
  }
  else if (picker < 40) { //if picker is under 40, Windows key.
    Keyboard.write(KEY_LEFT_GUI);
  }
  else { //if picker is 50 or lower, press tab an arbitrary amount of times and then press enter.
    for (int i = 0; i < tabret; i++) {
      Keyboard.write(KEY_TAB);
      delay(100);
    }
    Keyboard.write(KEY_RETURN); //loop until "i" less than tabret, then press enter.
  }
  
// may remove this, its never really worked right
//  else { //any other number, move mouse in a random direction.
//    Serial.println("Just fuck my shit up fam.");
//    mousect = 0;
//    do {
//      randomSeed(analogRead(3)); //rerandomize seed every loop. this doesn't really work. it's too predictable.
//      mousex = random(-200, 200); //mousex and mousey are used to decide how far to move the mouse horizontally and vertically.
//      mousey = random(-200, 200);
//
//      delay(mousedelay * annoyance);
//
//      //used for debugging
//      Serial.print(mousex);
//      Serial.print(", ");
//      Serial.println(mousey);
//
//      Mouse.move(mousex, mousey); //actually move the mouse
//      mousect = mousect + 1; //increment mousect by 1 so the script knows when to stop moving the mouse.
//    } while ( mousect < (mousemove)); //when mousect equals mousemove, stop looping and restart the script.
//  }
}
