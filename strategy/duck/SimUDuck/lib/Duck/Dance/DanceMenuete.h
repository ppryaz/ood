#ifndef DANCE_MENUETE_H
#define DANCE_MENUETE_H

#include "IDanceBehavior.h"
#include <iostream>

class DanceMenuete : public IDanceBehavior {
public: 
	void Dance() override
	{
		std::cout << "Dance Menuete!!!" << std::endl;
	}
};

#endif
