#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>

void setup(){
setSyncProvider(RTC.get);
//Часы, минуты, секунды, день, месяц, год
setTime(17,35,0,26,3,2020);
RTC.set(now());
}
void loop(){
delay(100);
}
