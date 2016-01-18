#include <stdlib.h>
#include <stdarg.h>

#include "VGA.h"
#include "hogSetup.h"
#include "hogEngine.h"

#include "loadExemplo1.h"

void setup() {
  hogInit();
}

void loop() {
  desenhaRect(0,0,0,160,120);
  
  /****************/
  desenhaTela();
  delay(2000);
  /****************/
  
  loadExemplo1();
  
  desenhaRect(83,0,0,160,120);
  
  /****************/
  desenhaTela();
  delay(2000);
  /****************/
  
  desenhaRect(52,16,80,48,16);
  desenhaRect(52,32,64,16,16);
  
  /****************/
  desenhaTela();
  delay(2000);
  /****************/
  
  desenhaSprite(2,0,80);
  desenhaSprite(2,16,64);
  desenhaSprite(3,32,48);
  desenhaSprite(4,48,64);
  desenhaSprite(4,64,80);
  
  /****************/
  desenhaTela();
  delay(2000);
  /****************/
  
  desenhaSprite(5,40,72);
  desenhaSprite(5,32,56);
  desenhaSprite(5,16,72);
  
  /****************/
  desenhaTela();
  delay(2000);
  /****************/
  
  for(int i=0; i<10; i++){
    desenhaSprite(1,16*i,96);
    desenhaSprite(1,16*i,112);
  }
  
  /****************/
  desenhaTela();
  delay(2000);
  /****************/
  
  desenhaSprite(0,40,81);
  
  /****************/
  desenhaTela();
  delay(10000);
  /****************/
}
