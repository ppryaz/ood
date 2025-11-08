#ifndef DECOYDUCK_H
#define DECOYDUCK_H

#include "Duck.h"

#include <iostream>
#include <memory>

class DecoyDuck : public Duck
{
public:
	DecoyDuck()
        : Duck(FlyNoWay(), QuackNone(), NoDance())
	{
	}

	void Display() const override
	{
		std::cout << "I'm decoy duck" << std::endl;
	}

    void Dance() {}
};

#endif
