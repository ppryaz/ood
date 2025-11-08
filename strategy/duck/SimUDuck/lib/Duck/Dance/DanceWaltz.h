#ifndef DANCE_WALTZ_H
#define DANCE_WALTZ_H

#include "IDanceBehavior.h"
#include <iostream>

class DanceWaltz : public IDanceBehavior {
public: 
	void Dance() override {
		std::cout << "Dance Waltz!!!" << std::endl;
	}
};

#endif
