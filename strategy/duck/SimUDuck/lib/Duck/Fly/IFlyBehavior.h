#ifndef LAB01_SIMUDUCK_IFLYBEHAVIOR_H
#define LAB01_SIMUDUCK_IFLYBEHAVIOR_H

struct IFlyBehavior
{
	virtual ~IFlyBehavior(){};
	virtual void Fly() = 0;
	
	int flyCount = -1;
};

#endif
