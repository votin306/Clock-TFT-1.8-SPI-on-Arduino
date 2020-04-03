#include <Time.h>
#include <TFT.h> // Библиотека для работы с TFT-экраном
#include <SPI.h>
#include <Wire.h>
#include <DS1307RTC.h>
 
#define CS   10
#define DC   9
#define RESET  8  
 
// объявление выводов, работающих с экраном, для Arduino Leonardo
// #define CS   7
// #define DC   0
// #define RESET  1 
 
TFT myScreen = TFT(CS, DC, RESET);
 
// массив символов для вывода времени на экран
char sec[10];
char minu[11];
char hou[12];
char days[13];
char moht[14];
char years[15];
 
void setup(){
  myScreen.begin(); 
  myScreen.setRotation(2); 
  myScreen.background(0,0,0); // очистка экрана
  myScreen.stroke(255,0,255);  
  // увеличиваем размер шрифта для текста, выводимого в блоке loop() 
  myScreen.setTextSize(2);
  
}
void loop(){
  
  tmElements_t tm;
  if (RTC.read(tm)) {
    String elapsedTime = String(tm.Second);
    elapsedTime.toCharArray(sec,10);  
    String elapsedTime1 = String(tm.Minute);
    elapsedTime1.toCharArray(minu,11);
    String elapsedTime2 = String(tm.Hour);
    elapsedTime2.toCharArray(hou,12);
    String elapsedTime3 = String(tm.Day);
    elapsedTime3.toCharArray(days,13);
    String elapsedTime4 = String(tm.Month);
    elapsedTime4.toCharArray(moht,14);
    String elapsedTime5 = String(tmYearToCalendar(tm.Year));
    elapsedTime5.toCharArray(years,15);
    myScreen.stroke(0,255,0);  
    myScreen.circle (64, 80, 60);
    myScreen.text(sec,90,50);
    myScreen.text(":",79,50);
    myScreen.text(minu,55,50);
    myScreen.text(":",40,50);
    myScreen.text(hou,20,50);
    myScreen.text(days,45,70);
    myScreen.text(".",60,70);
    myScreen.text(moht,75,70);
    myScreen.text(years,42,100);
    delay(1000);
    myScreen.stroke(0,0,0);
    myScreen.text(sec,90,50);
    myScreen.text(":",79,50);
    myScreen.text(minu,55,50);
    myScreen.text(":",40,50);
    myScreen.text(hou,20,50);
    myScreen.text(days,45,70);
    myScreen.text(".",60,70);
    myScreen.text(moht,75,70);
    myScreen.text(years,42,100);
  }
}
