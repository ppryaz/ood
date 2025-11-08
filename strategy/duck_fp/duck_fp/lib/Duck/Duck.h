#ifndef DUCK_H
#define DUCK_H

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include "DuckStrategy.h"


class Duck
{
public:
    using FlyFunction = std::function<void()>;
    using QuackFunction = std::function<void()>;
    using DanceFunction = std::function<void()>;

    Duck(FlyFunction &&flyBehavior,
        QuackFunction &&quackBehavior, DanceFunction &&danceBehavior)
		: m_quackBehavior(std::move(quackBehavior))
	{
		if (!m_quackBehavior) return;
		SetFlyBehavior(std::move(flyBehavior));
		SetDanceBehavior(std::move(danceBehavior));
        int flyCounter = 0;
	}

    void Quack() const { m_quackBehavior(); }

	void Swim()
	{
		std::cout << "I'm swimming" << std::endl;
	}

	void Fly()
	{		
        if (flyCounter % 2 != 0 && flyCounter > 0) Quack();
        m_flyBehavior();
        flyCounter = commonFly;
	}

    void Dance()
	{
//		std::cout << "I'm Dancing" << std::endl;
        m_danceBehavior();
	}

    void SetFlyBehavior(FlyFunction&& flyBehavior)
	{
		if(!flyBehavior) return;
		m_flyBehavior = std::move(flyBehavior);
	}
	
    void SetDanceBehavior(QuackFunction &&danceBehavior)
	{
		if(!danceBehavior);
		m_danceBehavior = std::move(danceBehavior);
	}
	

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
    FlyFunction	m_flyBehavior;
    QuackFunction m_quackBehavior;
    DanceFunction m_danceBehavior;

    int flyCounter = 0;
};

#endif
