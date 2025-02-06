/**
 * e-mail : openprogramming23@gmail.com
 * gitHub : https://github.com/RS-malik-el
 * 
 * @AUTHEUR : Exaucé KIMBEMBE / @OpenProgramming
 * DATE : 25/07/2022
 * MODIFIER : 06/02/2055
 * 
 * @Board : arduino uno
 * 
 * matrice leds 8x8 max7219
 * 
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
**/

#include <simple_matrix.h>

#define DEL 250 // Temps de défilement des caractères
#define CS_PIN 2 

simpleMatrix afficheur(CS_PIN,2); 

uint8_t coeur[8]={
  B01100000,
  B11110000,
  B11111000,
  B01111100,
  B01111110,
  B11111100,
  B11110000,
  B01100000
};

uint8_t c[16]={// pouce et coeur 
  B00000000,
  B00111110,
  B00111110,
  B00111110,
  B11111110,
  B11111110,
  B00011110,
  B00000000,
  B01100000,
  B11110000,
  B11111000,
  B01111100,
  B01111110,
  B11111100,
  B11110000,
  B01100000
};

void setup() {
  afficheur.begin();
  afficheur.invertIndividualDisplays(true);
  afficheur.setIntensity(3);
  afficheur.clearDisplay();
}

void loop() {
  afficheur.scrollBuffer(coeur,DEL,8);
  delay(500);
  afficheur.scrollBuffer(c,DEL,16);
  delay(500);
}
