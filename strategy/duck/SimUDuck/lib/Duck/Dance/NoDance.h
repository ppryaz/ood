#ifndef NO_DANCE_H
#define NO_DANCE_H

#include "IDanceBehavior.h"

class NoDance : public IDanceBehavior
{
public:
	void Dance() override {}
};

#endif
