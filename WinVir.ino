#include <Keyboard.h>

long randomdelay;
int picker;
float ms;
float mins;
long secs;
int tabret;

String stringOne = "m: Next boi is in ";
String stringTwo = "s. Picker is at ";
String stringThree = "/60, so it'll be a ";
String stringFour = "Annoyance is at ";

// how annoying you want this script to be, lower is more annoying. recommended between 1 and 5
int annoyance = 1;

void setup() {
  Serial.println("starting..");
  Keyboard.begin(); //start emulating keyboard
  delay(10000);
  Serial.begin(9600);
  Serial.print(stringFour);
  Serial.println(annoyance);
}

void loop() {
  //initial seed and starting values for shit modified by annoyance factor
  randomSeed(analogRead(0));
  randomdelay = random(5000, 30000); //delay between each annoyance method
  ms = millis(); //keeps track of how long the script has been running
  mins = ms / 60000;
  picker = random(1, 60); //used to choose which method to annoy the user with.
  tabret = random(1, 16); //used to press tab a certain amount of times in method 5
  randomdelay = annoyance * randomdelay;
  secs = randomdelay / 1000;

  //array for method 6
  String banstring[] = {
    "bro weed lol",
    "hitler did nothing wrong",
    "i'm not convinced that the jews didn't do 9/11",
    "elon musk is going to save the planet",
    "black people commit 60% of ALL violent crime",
    "donald trump was a greater president than lincoln",
    "i am the least racist person there is",
    "laziness a trait in blacks",
    "i don't have a racist bone in my body",
    "you have to treat women like shit",
    "i cherish women",
    "peach tree dish",
    "i'm a very intelligent person",
  };

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
  else {
    Serial.println("stringboi");
  }

  delay(randomdelay); //delays the time set above before pressing a key

//method 1
  if (picker < 10) { //if picker is under 10, spacebar.
    Keyboard.write(' ');
  }
//method 2
  else if (picker < 20) { //if picker is under 20, backspace.
    Keyboard.write(KEY_BACKSPACE);
  }
//method 3
  else if (picker < 30) { //if picker is under 30, alt-tab.
    Keyboard.press(KEY_LEFT_ALT);
    delay(100);
    Keyboard.press(KEY_TAB);
    Keyboard.releaseAll();
  }
//method 4
  else if (picker < 40) { //if picker is under 40, Windows key.
    Keyboard.write(KEY_LEFT_GUI);
  }
//method 5
  else if (picker < 50) { //if picker is 50 or lower, press tab an arbitrary amount of times and then press enter.
    for (int i = 0; i < tabret; i++) {
      Keyboard.write(KEY_TAB);
      delay(100);
    }
    Keyboard.write(KEY_RETURN);
  }
//method 6
 else {
  Keyboard.println(banstring[random(0,12)]); //send a string pulled from the banstring array
 }
}
