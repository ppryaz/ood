#ifndef IDANCE_BEHAVIOR_H
#define IDANCE_BEHAVIOR_H

struct IDanceBehavior
{
	virtual ~IDanceBehavior() {};
	virtual void Dance() = 0;
};

#endif