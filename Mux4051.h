#ifndef MUX4051_H
#define MUX4051_H

#include <Arduino.h>
#include <FastGPIO.h>

class Mux4051
{
	private:
	int aA;
	int aB;
	int aC;
	int amax;	//liczba kanałów w linii
	int a_in;	//numer wejścia analogowego A0 - A5
	int del;	//opoznienie
	int in_NO;	//aktualny numer wejścia mux
	
	ABC_clear(void);
	
	public:
	begin(int IN, int A, int B, int C, int max, int delau);
	set_out(char value);
	int read(void);
	uint16_t readStep(void);
	uint16_t readStep1(void);
	
	Reset(void);

};


#endif /* MUX4051_H */