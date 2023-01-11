#include <FastLED.h>

#define LED_PIN 7
#define NUM_LEDS 484
#define NUM_ROWS 22
#define NUM_COLS 22

CRGB leds[NUM_LEDS];

void (*resetFunc)(void) = 0;
unsigned long time;
unsigned long tm;

int buttonValue = A0;



int top;
int left;
int right;
int mid;
int tp;

//check if enemy is killed
bool enemy1Killed = false;
bool enemy2Killed = false;
bool enemy3Killed = false;
bool enemy4Killed = false;
bool enemy5Killed = false;
bool enemy6Killed = false;
bool enemy7Killed = false;
bool enemy8Killed = false;
bool enemy9Killed = false;
bool enemy10Killed = false;
bool allEnemiesKilled = false;

bool hlDest = false;
bool hmDest = false;
bool hrDest = false;


//house bottom variables
int hbrm = 414;
int hbm = 407;
int hblm = 399;

//house mid variables
int hrm = 377;
int hmm = 384;
int hlm = 392;

//house top variables
int htr = 370;
int htm = 363;
int htl = 355;

void setup() {


  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);

  top = 452;
  left = 472;
  right = 470;
  mid = 471;
  tp = top - 1;

//Spawning in Player and houses
  //------------ Player -----------
  leds[right] = CRGB(0, 0, 255);
  leds[mid] = CRGB(0, 0, 255);
  leds[left] = CRGB(0, 0, 255);
  leds[top] = CRGB(0, 0, 255);

  //------------ Houses Bottom -----------
  leds[hbrm + 1] = CRGB(0, 155, 155);
  leds[hbrm] = CRGB(0, 155, 155);  //Right House
  leds[hbrm - 1] = CRGB(0, 155, 155);

  leds[hbm + 1] = CRGB(0, 155, 155);
  leds[hbm] = CRGB(0, 155, 155);  //Mid
  leds[hbm - 1] = CRGB(0, 155, 155);

  leds[hblm + 1] = CRGB(0, 155, 155);
  leds[hblm] = CRGB(0, 155, 155);  //Left
  leds[hblm - 1] = CRGB(0, 155, 155);


  //------------- Houses Mid --------------
  leds[hlm + 1] = CRGB(0, 155, 155);
  leds[hlm] = CRGB(0, 155, 155);  //Left
  leds[hlm - 1] = CRGB(0, 155, 155);

  leds[hmm + 1] = CRGB(0, 155, 155);
  leds[hmm] = CRGB(0, 155, 155);  //Mid
  leds[hmm - 1] = CRGB(0, 155, 155);

  leds[hrm + 1] = CRGB(0, 155, 155);
  leds[hrm] = CRGB(0, 155, 155);  //Right
  leds[hrm - 1] = CRGB(0, 155, 155);

  //------------- Houses Top ---------------
  leds[htr] = CRGB(0, 155, 155);  //Right
  leds[htm] = CRGB(0, 155, 155);  //Mid
  leds[htl] = CRGB(0, 155, 155);  //Left


  FastLED.show();
  Serial.begin(9600);
}

void loop() {
  time = millis() / 1000;

  //shot T/F checks
  bool firstShotFired = false;
  bool secondShot = false;
  bool thirdShot = false;
  bool fourthShot = false;
  bool fifthShot = false;
  bool sixthShot = false;
  bool seventhShot = false;
  bool eigthShot = false;
  bool ninthShot = false;
  bool tenthShot = false;
  bool eleventhShot = false;
  bool twelfthShot = false;
  bool thirteenthShot = false;
  bool fourteenthShot = false;
  bool fifteenthShot = false;
  bool sixteenthShot = false;
  bool seventeenthShot = false;
  bool eighteenthShot = false;
  bool nineteenthShot = false;
  bool twentiethShot = false;

  //shot position calculations
  int dist1;
  int subtractDist;
  int firstShotDist;

  int dist2;
  int subtractDist2;
  int secondShotDist;

  int dist3;
  int subtractDist3;
  int thirdShotDist;

  int dist4;
  int subtractDist4;
  int fourthShotDist;

  int dist5;
  int subtractDist5;
  int fifthShotDist;

  int dist6;
  int subtractDist6;
  int sixthShotDist;

  int dist7;
  int subtractDist7;
  int seventhShotDist;

  int dist8;
  int subtractDist8;
  int eigthShotDist;

  int dist9;
  int subtractDist9;
  int ninthShotDist;

  int dist10;
  int subtractDist10;
  int tenthShotDist;

  int dist11;
  int subtractDist11;
  int eleventhShotDist;

  int dist12;
  int subtractDist12;
  int twelfthShotDist;

  int dist13;
  int subtractDist13;
  int thirteenthShotDist;

  int dist14;
  int subtractDist14;
  int fourteenthShotDist;

  int dist15;
  int subtractDist15;
  int fifteenthShotDist;

  int dist16;
  int subtractDist16;
  int sixteenthShotDist;

  int dist17;
  int subtractDist17;
  int seventeenthShotDist;

  int dist18;
  int subtractDist18;
  int eighteenthShotDist;

  int dist19;
  int subtractDist19;
  int nineteenthShotDist;

  int dist20;
  int subtractDist20;
  int twentiethShotDist;



  int temp = analogRead(buttonValue);

  //checks if the houses (left, right, middle) have been destroyed (hbrm = house bottom right middle; hrm = house right middle; htr = house top - right)
  if (leds[hbrm] == CRGB(0, 0, 0) && leds[hbrm + 1] == CRGB(0, 0, 0) && leds[hbrm - 1] == CRGB(0, 0, 0) && leds[hrm] == CRGB(0, 0, 0) && leds[hrm + 1] == CRGB(0, 0, 0) && leds[hrm - 1] == CRGB(0, 0, 0) && leds[htr] == CRGB(0, 0, 0)) {
    hrDest = true;
  }
  //(hblm = house bottom left middle; hlm = house left middle; htl = house top - left)
  if (leds[hblm] == CRGB(0, 0, 0) && leds[hblm + 1] == CRGB(0, 0, 0) && leds[hblm - 1] == CRGB(0, 0, 0) && leds[hlm] == CRGB(0, 0, 0) && leds[hlm + 1] == CRGB(0, 0, 0) && leds[hlm - 1] == CRGB(0, 0, 0) && leds[htl] == CRGB(0, 0, 0)) {
    hlDest = true;
  }
  //(hbm = house bottom  middle; hmm = house middle middle; htm = house top - middle)
  if (leds[hbm] == CRGB(0, 0, 0) && leds[hbm + 1] == CRGB(0, 0, 0) && leds[hbm - 1] == CRGB(0, 0, 0) && leds[hmm] == CRGB(0, 0, 0) && leds[hmm + 1] == CRGB(0, 0, 0) && leds[hmm - 1] == CRGB(0, 0, 0) && leds[htm] == CRGB(0, 0, 0)) {
    hmDest = true;
  }


  //------------------------------------------------------------ Enemy Movement -------------------------------------------------------------


  if (time % 2 == 0) {
    
    //enemies move based off of a modulo calculation on time (every 2 seconds the enemies itterate forward)
    if (enemy1Killed == false) {
      leds[time] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy1Killed == true) {
      leds[time] = CRGB(0, 0, 0);
    }

    if (enemy2Killed == false) {
      leds[time + 2] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy2Killed == true) {
      leds[time + 2] = CRGB(0, 0, 0);
    }

    if (enemy3Killed == false) {
      leds[time + 4] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy3Killed == true) {
      leds[time + 4] = CRGB(0, 0, 0);
    }

    if (enemy4Killed == false) {
      leds[time + 6] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy4Killed == true) {
      leds[time + 6] = CRGB(0, 0, 0);
    }

    if (enemy5Killed == false) {
      leds[time + 8] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy5Killed == true) {
      leds[time + 8] = CRGB(0, 0, 0);
    }

    if (enemy6Killed == false) {
      leds[time + 10] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy6Killed == true) {
      leds[time + 10] = CRGB(0, 0, 0);
    }

    if (enemy7Killed == false) {
      leds[time + 12] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy7Killed == true) {
      leds[time + 12] = CRGB(0, 0, 0);
    }
    
    if (enemy8Killed == false) {
      leds[time + 14] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy8Killed == true) {
      leds[time + 14] = CRGB(0, 0, 0);
    }

    if (enemy9Killed == false) {
      leds[time + 16] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy9Killed == true) {
      leds[time + 16] = CRGB(0, 0, 0);
    }
    /*
    if (enemy10Killed == false) {
      leds[time + 18] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (enemy10Killed == true) {
      leds[time + 18] = CRGB(0, 0, 0);
    }*/

    //turns off lights behind the enemy path
    if (time >= 2) {
      leds[time - 2] = CRGB(0, 0, 0);
      FastLED.show();
    }
  }
  //-------------------------------------------- Win Function --------------------------------------------
  
    //check if all enemies are clear, if so, clear the board of LEDs
  if (enemy9Killed && enemy8Killed && enemy7Killed && enemy6Killed && enemy5Killed && enemy4Killed && enemy3Killed
      && enemy2Killed && enemy1Killed) {
    FastLED.clear();

    //displaying a win "animation" before showing "WIN" text
    for (int i; i < 484; i++) {
      leds[i] = CRGB(random(0, 255), random(0, 255), random(0, 255));
      FastLED.show();
      
      //if at the end of LED strip
      if (i == 483) {
        FastLED.clear();
        //left side 'W'
        leds[46] = CRGB(0, 255, 0);
        leds[85] = CRGB(0, 255, 0);
        leds[90] = CRGB(0, 255, 0);
        leds[129] = CRGB(0, 255, 0);
        leds[134] = CRGB(0, 255, 0);
        leds[173] = CRGB(0, 255, 0);
        leds[178] = CRGB(0, 255, 0);
        //right side 'W'
        leds[50] = CRGB(0, 255, 0);
        leds[81] = CRGB(0, 255, 0);
        leds[94] = CRGB(0, 255, 0);
        leds[125] = CRGB(0, 255, 0);
        leds[138] = CRGB(0, 255, 0);
        leds[169] = CRGB(0, 255, 0);
        leds[182] = CRGB(0, 255, 0);
        //'W' peak
        leds[172] = CRGB(0, 255, 0);
        leds[170] = CRGB(0, 255, 0);
        leds[127] = CRGB(0, 255, 0);
        leds[136] = CRGB(0, 255, 0);


        //top 'I'
        leds[53] = CRGB(0, 255, 0);
        leds[54] = CRGB(0, 255, 0);
        leds[55] = CRGB(0, 255, 0);
        leds[56] = CRGB(0, 255, 0);
        leds[57] = CRGB(0, 255, 0);
        //mid 'I'
        leds[76] = CRGB(0, 255, 0);
        leds[99] = CRGB(0, 255, 0);
        leds[120] = CRGB(0, 255, 0);
        leds[143] = CRGB(0, 255, 0);
        leds[164] = CRGB(0, 255, 0);
        //bottom 'I'
        leds[185] = CRGB(0, 255, 0);
        leds[186] = CRGB(0, 255, 0);
        leds[187] = CRGB(0, 255, 0);
        leds[188] = CRGB(0, 255, 0);
        leds[189] = CRGB(0, 255, 0);
        

        //left 'N'
        leds[60] = CRGB(0, 255, 0);
        leds[71] = CRGB(0, 255, 0);
        leds[104] = CRGB(0, 255, 0);
        leds[115] = CRGB(0, 255, 0);
        leds[148] = CRGB(0, 255, 0);
        leds[159] = CRGB(0, 255, 0);
        leds[192] = CRGB(0, 255, 0);
        //Slash 'N'
        leds[70] = CRGB(0, 255, 0);
        leds[105] = CRGB(0, 255, 0);
        leds[113] = CRGB(0, 255, 0);
        leds[150] = CRGB(0, 255, 0);
        leds[156] = CRGB(0, 255, 0);
        leds[195] = CRGB(0, 255, 0);
        //right 'N'
        leds[64] = CRGB(0, 255, 0);
        leds[67] = CRGB(0, 255, 0);
        leds[108] = CRGB(0, 255, 0);
        leds[111] = CRGB(0, 255, 0);
        leds[152] = CRGB(0, 255, 0);
        leds[155] = CRGB(0, 255, 0);
        leds[196] = CRGB(0, 255, 0);
        
        //shows "WIN" text for 10 sec before resetting the system
        FastLED.show();
        delay(10000);
        resetFunc();
      }
    }
  }
  //---------- Lose Function -------------
  else if (hlDest && hrDest && hmDest){
    FastLED.clear();

    //just like win "animation" but only shows red LEDs
    for (int j; j < 484; j++) {
      leds[j] = CRGB(255, 0, 0);
      FastLED.show();
      if (j == 483) {
        resetFunc();
      }      
    }
  }




  //------------------------------------------------------------ Player Controls ------------------------------------------------------------
  
  //with resistors and buttons connected in series, the temp of each button being clicked had a different value
  if (temp < 100) {
    //do nothing - stops ship from moving + firing

  } else if (temp < 250 && top > 440) { //moving left
    
    Serial.println("button left pressed");


    leds[right++] = CRGB(0, 0, 255);
    leds[mid++] = CRGB(0, 0, 255);
    leds[left++] = CRGB(0, 0, 255);
    leds[top--] = CRGB(0, 0, 255);

    //turns off LEDs behind the ship making it appear to move
    leds[right - 2] = CRGB(0, 0, 0);
    leds[top + 2] = CRGB(0, 0, 0);
    FastLED.show();

    tp = top;

    delay(400);
  } else if (temp > 900 && temp < 1000 && top < 461) {  //moving right
    Serial.println("button right pressed");
    leds[right--] = CRGB(0, 0, 255);
    leds[mid--] = CRGB(0, 0, 255);
    leds[left--] = CRGB(0, 0, 255);
    leds[top++] = CRGB(0, 0, 255); // Edting note - notice how the top of the ship increments opposite to the body, 
                                   // this is because our LED "sheet" was essentially one long strip
 
    leds[left + 2] = CRGB(0, 0, 0);
    leds[top - 2] = CRGB(0, 0, 0);
    FastLED.show();

    tp = top - 2;

    delay(400);
  }

  //---------------------------------------------------------- Player Shooting Check --------------------------------------------------------
  if (temp > 400 && temp < 500 && top > 439 && top < 462) {
    
    Serial.println("button shoot pressed");
    firstShotFired = true;
    //distance from the top of the ship to the start of the line
    dist1 = (tp - 439);
    subtractDist = -dist1 - dist1; //could also just do (dist * -2)
    firstShotDist = tp + subtractDist; //placing the shot
    leds[firstShotDist] = CRGB(0, 255, 0);


  //checking if the bullet hits an enemy on the first line of lights it spawns on 
    if (firstShotDist == time) {
      enemy1Killed = true;
    }
    if (firstShotDist == time + 2) {
      enemy2Killed = true;
    }
    if (firstShotDist == time + 4) {
      enemy3Killed = true;
    }
    if (firstShotDist == time + 6) {
      enemy4Killed = true;
    }
    if (firstShotDist == time + 8) {
      enemy5Killed = true;
    }
    if (firstShotDist == time + 10) {
      enemy6Killed = true;
    }
    if (firstShotDist == time + 12) {
      enemy7Killed = true;
    }
    if (firstShotDist == time + 14) {
      enemy8Killed = true;
    }
    if (firstShotDist == time + 16) {
      enemy9Killed = true;
    }
    if (firstShotDist == time + 18) {
      enemy10Killed = true;
    }

    FastLED.show();
  }

  //------------------------------------------------------------ Shot Controller ------------------------------------------------------------
  if (firstShotFired) {
    //the same calculation from above repeats, but replaces the position of the top of the ship with the position of the shot
    dist2 = (firstShotDist - 417);
    subtractDist2 = -dist2 - dist2;
    secondShotDist = firstShotDist + subtractDist2;

    if ((secondShotDist + 1) == time) {
      enemy1Killed = true;
    }
    if (secondShotDist + 1 == time + 2) {
      enemy2Killed = true;
    }
    if (secondShotDist + 1 == time + 4) {
      enemy3Killed = true;
    }
    if (secondShotDist + 1 == time + 6) {
      enemy4Killed = true;
    }
    if (secondShotDist + 1 == time + 8) {
      enemy5Killed = true;
    }
    if (secondShotDist + 1 == time + 10) {
      enemy6Killed = true;
    }
    if (secondShotDist + 1 == time + 12) {
      enemy7Killed = true;
    }
    if (secondShotDist + 1 == time + 14) {
      enemy8Killed = true;
    }
    if (secondShotDist + 1 == time + 16) {
      enemy9Killed = true;
    }
    if (secondShotDist + 1 == time + 18) {
      enemy10Killed = true;
    }

    leds[firstShotDist] = CRGB(0, 0, 0);
    leds[secondShotDist + 1] = CRGB(0, 255, 0);
    secondShot = true;
    FastLED.show();
    firstShotFired = false;

    if (secondShot) {
      
      
      dist3 = (secondShotDist - 395);
      subtractDist3 = -dist3 - dist3;
      thirdShotDist = secondShotDist + subtractDist3;

      if (thirdShotDist == time) {
        enemy1Killed = true;
      }
      if (thirdShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (thirdShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (thirdShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (thirdShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (thirdShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (thirdShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (thirdShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (thirdShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (thirdShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[secondShotDist + 1] = CRGB(0, 0, 0);
      leds[thirdShotDist] = CRGB(0, 255, 0);
      thirdShot = true;
      FastLED.show();
      secondShot = false;


    }
    if (thirdShot) {
      
      dist4 = (thirdShotDist - 373);
      subtractDist4 = -dist4 - dist4;
      fourthShotDist = thirdShotDist + subtractDist4;

      if ((fourthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (fourthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (fourthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (fourthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (fourthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (fourthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (fourthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (fourthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (fourthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (fourthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[thirdShotDist] = CRGB(0, 0, 0);
      leds[fourthShotDist + 1] = CRGB(0, 255, 0);
      fourthShot = true;
      FastLED.show();
      thirdShot = false;
    }
    if (fourthShot) {
      
      dist5 = (fourthShotDist - 351);
      subtractDist5 = -dist5 - dist5;
      fifthShotDist = fourthShotDist + subtractDist5;

      if (fifthShotDist == time) {
        enemy1Killed = true;
      }
      if (fifthShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (fifthShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (fifthShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (fifthShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (fifthShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (fifthShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (fifthShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (fifthShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (fifthShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[fourthShotDist + 1] = CRGB(0, 0, 0);
      leds[fifthShotDist] = CRGB(0, 255, 0);
      fifthShot = true;
      FastLED.show();
      fourthShot = false;
    }
    if (fifthShot) {
      
      dist6 = (fifthShotDist - 329);
      subtractDist6 = -dist6 - dist6;
      sixthShotDist = fifthShotDist + subtractDist6;

      if ((sixthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (sixthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (sixthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (sixthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (sixthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (sixthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (sixthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (sixthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (sixthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (sixthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[fifthShotDist] = CRGB(0, 0, 0);
      leds[sixthShotDist + 1] = CRGB(0, 255, 0);
      sixthShot = true;
      FastLED.show();
      fifthShot = false;
    }
    if (sixthShot) {
      
      dist7 = (sixthShotDist - 307);
      subtractDist7 = -dist7 - dist7;
      seventhShotDist = sixthShotDist + subtractDist7;

      if (seventhShotDist == time) {
        enemy1Killed = true;
      }
      if (seventhShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (seventhShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (seventhShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (seventhShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (seventhShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (seventhShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (seventhShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (seventhShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (seventhShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[sixthShotDist + 1] = CRGB(0, 0, 0);
      leds[seventhShotDist] = CRGB(0, 255, 0);
      seventhShot = true;
      FastLED.show();
      sixthShot = false;
    }
    if (seventhShot) {
      
      dist8 = (seventhShotDist - 285);
      subtractDist8 = -dist8 - dist8;
      eigthShotDist = seventhShotDist + subtractDist8;

      if ((eigthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (eigthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (eigthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (eigthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (eigthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (eigthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (eigthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (eigthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (eigthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (eigthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[seventhShotDist] = CRGB(0, 0, 0);
      leds[eigthShotDist + 1] = CRGB(0, 255, 0);
      eigthShot = true;
      FastLED.show();
      seventhShot = false;
    }
    if (eigthShot) {
      

      dist9 = (eigthShotDist - 263);
      subtractDist9 = -dist9 - dist9;
      ninthShotDist = eigthShotDist + subtractDist9;

      if (ninthShotDist == time) {
        enemy1Killed = true;
      }
      if (ninthShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (ninthShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (ninthShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (ninthShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (ninthShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (ninthShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (ninthShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (ninthShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (ninthShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[eigthShotDist + 1] = CRGB(0, 0, 0);
      leds[ninthShotDist] = CRGB(0, 255, 0);
      ninthShot = true;
      FastLED.show();
      eigthShot = false;
    }
    if (ninthShot) {
      
      dist10 = (ninthShotDist - 241);
      subtractDist10 = -dist10 - dist10;
      tenthShotDist = ninthShotDist + subtractDist10;

      if ((tenthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (tenthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (tenthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (tenthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (tenthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (tenthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (tenthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (tenthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (tenthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (tenthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[ninthShotDist] = CRGB(0, 0, 0);
      leds[tenthShotDist + 1] = CRGB(0, 255, 0);
      tenthShot = true;
      FastLED.show();
      ninthShot = false;
    }
    if (tenthShot) {
      
      dist11 = (tenthShotDist - 219);
      subtractDist11 = -dist11 - dist11;
      eleventhShotDist = tenthShotDist + subtractDist11;

      if (eleventhShotDist == time) {
        enemy1Killed = true;
      }
      if (eleventhShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (eleventhShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (eleventhShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (eleventhShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (eleventhShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (eleventhShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (eleventhShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (eleventhShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (eleventhShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[tenthShotDist + 1] = CRGB(0, 0, 0);
      leds[eleventhShotDist] = CRGB(0, 255, 0);
      eleventhShot = true;
      FastLED.show();
      tenthShot = false;
    }
    if (eleventhShot) {
      
      dist12 = (eleventhShotDist - 197);
      subtractDist12 = -dist12 - dist12;
      twelfthShotDist = eleventhShotDist + subtractDist12;

      if ((twelfthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (twelfthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (twelfthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (twelfthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (twelfthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (twelfthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (twelfthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (twelfthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (twelfthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (twelfthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[eleventhShotDist] = CRGB(0, 0, 0);
      leds[twelfthShotDist + 1] = CRGB(0, 255, 0);
      twelfthShot = true;
      FastLED.show();
      eleventhShot = false;
    }
    if (twelfthShot) {
     
      dist13 = (twelfthShotDist - 175);
      subtractDist13 = -dist13 - dist13;
      thirteenthShotDist = twelfthShotDist + subtractDist13;

      if (thirteenthShotDist == time) {
        enemy1Killed = true;
      }
      if (thirteenthShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (thirteenthShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (thirteenthShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (thirteenthShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (thirteenthShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (thirteenthShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (thirteenthShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (thirteenthShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (thirteenthShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[twelfthShotDist + 1] = CRGB(0, 0, 0);
      leds[thirteenthShotDist] = CRGB(0, 255, 0);
      thirteenthShot = true;
      FastLED.show();
      twelfthShot = false;
    }
    if (thirteenthShot) {
      
      dist14 = (thirteenthShotDist - 153);
      subtractDist14 = -dist14 - dist14;
      fourteenthShotDist = thirteenthShotDist + subtractDist14;

      if ((fourteenthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (fourteenthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[thirteenthShotDist] = CRGB(0, 0, 0);
      leds[fourteenthShotDist + 1] = CRGB(0, 255, 0);
      fourteenthShot = true;
      FastLED.show();
      thirteenthShot = false;
    }
    if (fourteenthShot) {
      
      dist15 = (fourteenthShotDist - 131);
      subtractDist15 = -dist15 - dist15;
      fifteenthShotDist = fourteenthShotDist + subtractDist15;

      if (fifteenthShotDist == time) {
        enemy1Killed = true;
      }
      if (fifteenthShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (fifteenthShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (fifteenthShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (fifteenthShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (fifteenthShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (fifteenthShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (fifteenthShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (fifteenthShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (fifteenthShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[fourteenthShotDist + 1] = CRGB(0, 0, 0);
      leds[fifteenthShotDist] = CRGB(0, 255, 0);
      fifteenthShot = true;
      FastLED.show();
      fourteenthShot = false;
    }
    if (fifteenthShot) {
      
      dist16 = (fifteenthShotDist - 109);
      subtractDist16 = -dist16 - dist16;
      sixteenthShotDist = fifteenthShotDist + subtractDist16;

      if ((sixteenthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (sixteenthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[fifteenthShotDist] = CRGB(0, 0, 0);
      leds[sixteenthShotDist + 1] = CRGB(0, 255, 0);
      sixteenthShot = true;
      FastLED.show();
      fifteenthShot = false;
    }
    if (sixteenthShot) {
      
      dist17 = (sixteenthShotDist - 87);
      subtractDist17 = -dist17 - dist17;
      seventeenthShotDist = sixteenthShotDist + subtractDist17;

      if (seventeenthShotDist == time) {
        enemy1Killed = true;
      }
      if (seventeenthShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (seventeenthShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (seventeenthShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (seventeenthShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (seventeenthShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (seventeenthShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (seventeenthShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (seventeenthShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (seventeenthShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[sixteenthShotDist + 1] = CRGB(0, 0, 0);
      leds[seventeenthShotDist] = CRGB(0, 255, 0);
      seventeenthShot = true;
      FastLED.show();
      sixteenthShot = false;
    }
    if (seventeenthShot) {
      
      dist18 = (seventeenthShotDist - 65);
      subtractDist18 = -dist18 - dist18;
      eighteenthShotDist = seventeenthShotDist + subtractDist18;

      if ((eighteenthShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 2) {
        enemy2Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 4) {
        enemy3Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 6) {
        enemy4Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 8) {
        enemy5Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 10) {
        enemy6Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 12) {
        enemy7Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 14) {
        enemy8Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 16) {
        enemy9Killed = true;
      }
      if (eighteenthShotDist + 1 == time + 18) {
        enemy10Killed = true;
      }

      leds[seventeenthShotDist] = CRGB(0, 0, 0);
      leds[eighteenthShotDist + 1] = CRGB(0, 255, 0);
      eighteenthShot = true;
      FastLED.show();
      seventeenthShot = false;
      Serial.println(eighteenthShotDist);
    }
    if (eighteenthShot) {
      
      dist19 = (eighteenthShotDist - 43);
      subtractDist19 = -dist19 - dist19;
      nineteenthShotDist = eighteenthShotDist + subtractDist19;

      if (nineteenthShotDist == time) {
        enemy1Killed = true;
      }
      if (nineteenthShotDist == time + 2) {
        enemy2Killed = true;
      }
      if (nineteenthShotDist == time + 4) {
        enemy3Killed = true;
      }
      if (nineteenthShotDist == time + 6) {
        enemy4Killed = true;
      }
      if (nineteenthShotDist == time + 8) {
        enemy5Killed = true;
      }
      if (nineteenthShotDist == time + 10) {
        enemy6Killed = true;
      }
      if (nineteenthShotDist == time + 12) {
        enemy7Killed = true;
      }
      if (nineteenthShotDist == time + 14) {
        enemy8Killed = true;
      }
      if (nineteenthShotDist == time + 16) {
        enemy9Killed = true;
      }
      if (nineteenthShotDist == time + 18) {
        enemy10Killed = true;
      }

      leds[eighteenthShotDist + 1] = CRGB(0, 0, 0);
      leds[nineteenthShotDist] = CRGB(0, 255, 0);
      nineteenthShot = true;
      FastLED.show();
      eighteenthShot = false;
      Serial.println(nineteenthShotDist);
    }
    if (nineteenthShot) {
      
      dist20 = (nineteenthShotDist - 21);
      subtractDist20 = -dist20 - dist20;
      twentiethShotDist = nineteenthShotDist + subtractDist20;

      if ((twentiethShotDist + 1) == time) {
        enemy1Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 2) {
        enemy2Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 4) {
        enemy3Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 6) {
        enemy4Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 8) {
        enemy5Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 10) {
        enemy6Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 12) {
        enemy7Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 14) {
        enemy8Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 16) {
        enemy9Killed = true;
      }
      if ((twentiethShotDist + 1) == time + 18) {
        enemy10Killed = true;
      }

      leds[nineteenthShotDist] = CRGB(0, 0, 0);
      leds[twentiethShotDist + 1] = CRGB(0, 255, 0);
      twentiethShot = true;
      FastLED.show();
      nineteenthShot = false;
    }
    if (twentiethShot) {
      leds[twentiethShotDist + 1] = CRGB(0, 0, 0);
      twentiethShotDist = false;
      FastLED.show();
    }
  }
}