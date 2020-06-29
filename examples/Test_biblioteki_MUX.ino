#include <Mux4051.h>

#define LINE 5

Mux4051 mux; 

uint8_t licznik;

void setup() {
  // put your setup code here, to run once:
  mux.begin(A5,5,6,7,LINE,5);
  Serial.begin(9600);
  delay(1000);
  mux.Reset();
  licznik = 0;
  Serial.println("Start");

}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print(licznik);
  Serial.print(": ");
  Serial.print(mux.readStep());
  Serial.print("     ");
  if(++licznik == LINE)
  {
    licznik =0;
    Serial.println(" ");
    delay(500);
  }
  
}
