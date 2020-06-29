#ifndef DISP74595_H
#define DISP74595_H

#include <Rej74595.h>

#define MAXREG 20


class Disp74595
{
	private:
	int num;
	int typ;
	char oute;	//output enable pin
	Rej74595 rej[MAXREG];
	
	public:
	begin(int NO, int type,char latch, char outen, int delau);
	WriteDisplay(int val);
	StepDisplay(int val);
	LoopDisplay(void);
	int ReadFirst(void);
};






#endif /* DISP74595_H */