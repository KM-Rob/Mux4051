#include "Mux4051.h"

Mux4051::begin(int IN, int A, int B, int C, int max, int delau)
{
	aA = A;
	aB = B;
	aC = C;
	amax = max;
	pinMode(aA, OUTPUT);
	pinMode(aA, OUTPUT);
	pinMode(aA, OUTPUT);
	
	ABC_clear();
	
	a_in = IN;
	del = delau;
	
	Serial.begin(9600);
}


Mux4051::ABC_clear(void)
{
	digitalWrite(aA,LOW);	
	digitalWrite(aB,LOW);	
	digitalWrite(aC,LOW);	
}

Mux4051::set_out(char value)
{
ABC_clear();
  switch(value)
  {
  case 1:
    digitalWrite(aA,HIGH);
  break;
  case 2:
    digitalWrite(aB,HIGH);
  break;
  case 3:
    digitalWrite(aA,HIGH);
	digitalWrite(aB,HIGH);
  break;
  case 4:
    digitalWrite(aC,HIGH);
  break;
  case 5:
    digitalWrite(aA,HIGH);
	digitalWrite(aC,HIGH);
  break;
  case 6:
    digitalWrite(aB,HIGH);
	digitalWrite(aC,HIGH);	
  break;
  case 7:
    digitalWrite(aA,HIGH);
	digitalWrite(aB,HIGH);
	digitalWrite(aC,HIGH);
  break;  
  default:;

  }	
	
}



Mux4051::Reset(void)
{
	in_NO=0;
	
}

uint16_t Mux4051::readStep(void)
{
	uint16_t analog;
	
	set_out(in_NO);
	
	//Serial.print("  ");
	//Serial.print(in_NO);
	//Serial.print("  ");
	
	//delay(del);
	analog = uint16_t(analogRead(a_in));
	//delay(del);
	
	in_NO++;
	if(in_NO==amax) in_NO=0;
	
	return analog;
}


uint16_t Mux4051::readStep1(void)
{
	//set_out(in_NO);
	//if(in_NO==amax) in_NO=0;
	delay(del);
	return analogRead(a_in);
	
}


int Mux4051::read(void)
{
	return analogRead(a_in);
}