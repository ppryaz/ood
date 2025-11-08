#ifndef DUCK_H
#define DUCK_H

#include "Fly/IFlyBehavior.h"
#include "Quack/IQuakBehavior.h"
#include "Dance/NoDance.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

class Duck
{
public:
	Duck(std::unique_ptr<IFlyBehavior>&& flyBehavior,
		std::unique_ptr<IQuackBehavior>&& quackBehavior, std::unique_ptr<IDanceBehavior>&& danceBehavior)
		: m_quackBehavior(std::move(quackBehavior))
	{
		if (!m_quackBehavior) return;
		SetFlyBehavior(std::move(flyBehavior));
		SetDanceBehavior(std::move(danceBehavior));
	}

	void Quack() const
	{
		m_quackBehavior->Quack();
	}

	void Swim()
	{
		std::cout << "I'm swimming" << std::endl;
	}

	void Fly()
	{		
		if (m_flyBehavior->flyCount % 2 == 0 && m_flyBehavior->flyCount >= 0) Quack();
		m_flyBehavior->Fly();
	
	}

	virtual void Dance()
	{
		std::cout << "I'm Dancing" << std::endl;
		m_danceBehavior->Dance();
	}

	void SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior)
	{
		if(!flyBehavior) return;
		m_flyBehavior = std::move(flyBehavior);
	}
	
	void SetDanceBehavior(std::unique_ptr<IDanceBehavior> &&danceBehavior) 
	{
		if(!danceBehavior);
		m_danceBehavior = std::move(danceBehavior);
	}
	

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	std::unique_ptr<IFlyBehavior>	m_flyBehavior;
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};

#endif
