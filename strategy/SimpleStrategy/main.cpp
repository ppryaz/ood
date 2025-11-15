#include <iostream>
#include <memory>

struct MoveStrategy {
	virtual ~MoveStrategy() = default;
	virtual void move() = 0;
};

struct WalkStrategy : MoveStrategy {
	void move() override { std::cout << "Walk Strategy" << std::endl; }
};

struct DriveStrategy : MoveStrategy {
	void move() override { std::cout << "Drive Strategy" << std:: endl; }
};

struct ScooterStrategy : MoveStrategy {
	void move() override { std::cout << "Scooter Strategy" << std::endl; }
};

struct Human {
	std::unique_ptr<MoveStrategy>strategy;
	void setStrategy(std::unique_ptr<MoveStrategy> newStrategy) {
		std::cout << "Set Strategy" << std::endl;
		strategy = std::move(newStrategy);
	}
	
	void move() const {
		std::cout << "Call Strategy" << std::endl;
		if (strategy) strategy->move();
	}
};

int main() {
	std::cout << "Start" << std::endl;

	Human person;

	person.setStrategy(std::make_unique<WalkStrategy>());
	person.move();

	person.setStrategy(std::make_unique<DriveStrategy>());
	person.move();

	person.setStrategy(std::make_unique<ScooterStrategy>());
	person.move();
	
	std::cout << "Stop" << std::endl;

	return 0;
}