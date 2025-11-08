#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"

#include <memory>

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
        : Duck(FlyWithWings() , QuackNorm(), DanceMenuete())
	{
	}

	void Display() const override
	{
		std::cout << "I'm redhead duck" << std::endl;
	}
};

#endif
