#include <Mouse.h>
#include <Keyboard.h>

long randomdelay;
long mousedelay;
int mouserand;
int picker;
float time;
float mins;
long secs;
int mousex;
int mousey;
int mousect;
int tabret;

String stringOne = "m: Next boi is in ";
String stringTwo = "s. Picker is at ";
String stringThree = "/60, so it'll be a ";

// how annoying you want this script to be from 1-5
// 1 being almost unnoticeable and 5 making the PC unusable.
// should ideally be kept at 3 unless you're either playing the long con or you want to cripple someones computer.
int annoyance = 4;

void setup() {
  Keyboard.begin(); //start emulating mouse
  Mouse.begin(); //start emulating keyboard
  delay(10000);
  Serial.begin(9600);

  //these lines used to be required for randomness. they might still be, but need more testing.
  //randomSeed(analogRead(3));
  //picker = random(1, 60);

  Serial.print("Annoyance is at ");
  Serial.println(annoyance);
}

void loop() {
  randomSeed(analogRead(3)); //reads noise on analog pin 3 to emulate randomness.
  time = millis(); //keeps track of how long the script has been running
  picker = random(1, 60); //used to choose which key to annoy the user with.

  if (annoyance == 5) {
    randomdelay = random(500, 5000);
    mousedelay = random(10, 200);
    mouserand = random(10, 100);
  }
  if (annoyance == 4) {
    randomdelay = random(10000, 30000);
    mousedelay = random(1000, 3000);
    mouserand = random(10, 50);
  }
  if (annoyance == 3) {
    randomdelay = random(20000, 90000);
    mousedelay = random(1000, 15000);
    mouserand = random(3, 10);
  }
  if (annoyance == 2) {
    randomdelay = random(60000, 120000);
    mousedelay = random(1000, 20000);
    mouserand = random(2, 5);
  }
  if (annoyance == 1) {
    randomdelay = random(120000, 240000);
    mousedelay = random(3000, 25000);
    mouserand = random(1, 3);
  }

  mins = time / 1000 / 60;
  secs = randomdelay / 1000;

  //this block is used for debugging to see which key is going to be pressed next.
  String displayString = mins + stringOne + secs + stringTwo + picker + stringThree;
  Serial.print(displayString);

  if (picker < 10) Serial.println("spaceboi.");
  else if (picker < 20) Serial.println("backboi.");
  else if (picker < 30) Serial.println("taboi.");
  else if (picker < 40) Serial.println("winboi.");
  else if (picker < 50) Serial.println("returnboi.");
  else Serial.println("mouseboi.");

  delay(randomdelay); //delays the time set above before pressing a key.

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
  else if (picker < 50) { //if picker is under 50, press tab an arbitrary amount of times and then press enter.
    tabret = 0;
    do {
      randomSeed(analogRead(3)); //rerandomize seed.
      Keyboard.write(KEY_TAB);
      Serial.print("tabret is ");
      Serial.println(tabret);
      tabret = tabret + 1; //increment tabret by 1.
    } while ( tabret < (random(2, 15))); //if tabret equals this amount, stop looping and then press enter.
    delay(100);
    Keyboard.write(KEY_RETURN);
  }
  else { //any other number, move mouse in a random direction an arbitrary amount of times.
    Serial.println("Just fuck my shit up fam.");
    mousect = 0;
    do {
      randomSeed(analogRead(3));//rerandomize seed.
      mousex = random(-200, 200); //mousex and mousey are used to decide how far to move the mouse horizontally and vertically.
      mousey = random(-200, 200);

      delay(mousedelay);

      //used for debugging
      Serial.print(mousex);
      Serial.print(", ");
      Serial.println(mousey);

      Mouse.move(mousex, mousey); //actually move the mouse
      mousect = mousect + 1; //increment mousect by 1 so the script knows when to stop moving the mouse.
    } while ( mousect < (mouserand)); //if mousect equals this amount, stop looping and restart the script.
  }
}
