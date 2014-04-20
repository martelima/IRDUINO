/**
 * Programa para controlar um sistema de irrigação feito em arduino
 * @author Rafael Lima
 * @version 0.23
 */

#include <Time.h>
#include <TimeAlarms.h>
#include <LiquidCrystal.h>    //Biblioteca para Display LCD

#include "irduino.h"

#define BTN_SELECT 642
#define BTN_LEFT 413
#define BTN_RIGHT 0
#define BTN_UP 100
#define BTN_DOWN 259

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte pinoBotao = A0;

int valorBotao = 0;
int opcao_tela = 0;

void setup(){
	Serial.begin(9600);
	setTime(9,59,0,1,1,11); // set time to Saturday 8:29:00am Jan 1 2011
  
  lcd.clear(); 
}

void loop(){
  valorBotao = analogRead(pinoBotao);
  switch (opcao_tela) {
      case 1:
        menu();
        break;
      default:
        digitalClockDisplay();
        if((valorBotao <= BTN_SELECT)&&((valorBotao > BTN_LEFT)))
          opcao_tela = 1;
        else
          opcao_tela = 0;
        break;
  }
}

/*
 * Funções para Manipulação do display lcd:
 * E menus
 */

void digitalClockDisplay()
{
  // digital clock display of the time
  lcd.setCursor(0,0);
  if(hour()<10)
    lcd.print("     "); // 5c em branco
  else
    lcd.print("    "); // 4c em branco
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
  lcd.print("    "); // 4c em branco
}

void printDigits(int digits)
{
  lcd.print(":");
  if(digits < 10)
     lcd.print('0');
  lcd.print(digits);
}

void menu(){
  lcd.setCursor(0,1);
  navegarMenu();
  switch (opcao_tela) {
      case UI_SET_TIME:
        lcd.print(MENU_SET_TIME);
        break;
      case UI_MENU:
      default:
        lcd.print(MENU_INICIO);
        opcao_tela=UI_MENU;
  }
}

void navegarMenu(){
  valorBotao = analogRead(pinoBotao);
  if(valorBotao <= BTN_RIGHT){
  }else{
    if(valorBotao <= BTN_UP){
    }else{
      if(valorBotao <= BTN_DOWN){
      }else{
        if(valorBotao <= BTN_LEFT){
          opcao_tela = 0;
        }else{
          if(valorBotao <= BTN_SELECT){
          }
        }
      }
    }
  }
}