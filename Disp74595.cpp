#include "Disp74595.h"

Disp74595::begin(int NO, int type,char latch, char outen, int delau)
{
	num = NO;
	typ = type;
	oute = outen;
	for(int i=0;i<num;i++)
		rej[i].begin(OEL,latch,outen,delau);

	if(typ==LAT)
		{
		pinMode(oute,OUTPUT);
		digitalWrite(oute,LOW);
		}	
}

Disp74595::WriteDisplay(int val)
{
	for(int i=0;i<num;i++)
      rej[i].WriteDisplay(val);
	
}

Disp74595::StepDisplay(int val)
{
	rej[0].WriteDisplay(val);
    if(typ==LAT)digitalWrite(oute,HIGH);
	if(typ==LAT) delay(1);
	for(int i=1;i<num;i++)
      rej[i].WriteDisplay(0);
	if(typ==LAT) delay(1);
	if(typ==LAT)digitalWrite(oute,LOW);
}

Disp74595::LoopDisplay(void)
{
int a=0;
    a=rej[num-1].ReadValue()>>7;
    a = a&_BV(0);
    if(typ==LAT)digitalWrite(oute,HIGH);
	if(typ==LAT) delay(1); 
	for(int i=0;i<num;i++)
      a=rej[i].StepDisplay(a);	
  	if(typ==LAT) delay(1);
	if(typ==LAT)digitalWrite(oute,LOW);
}

int Disp74595::ReadFirst(void)
{
	return rej[0].ReadValue();
}