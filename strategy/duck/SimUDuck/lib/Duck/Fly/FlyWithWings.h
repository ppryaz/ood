#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		flyCount++;
		std::cout << "I'm flying with wings!!" << "Fly number:" << flyCount + 1 << std::endl;
	}

	
};

#endif
