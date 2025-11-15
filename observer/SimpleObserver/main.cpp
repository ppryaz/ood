// Pattern Observer

#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
	virtual void update(int value) = 0;
	
	virtual ~Observer() {};
};

class Subject {
public:
	std::vector<Observer*>observers;

	void attach(Observer *observer) {
		observers.push_back(observer);
	}
	
	void detach(Observer *observer)	{
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}
	void notify(int value) {
		for (Observer* e : observers) {
			e->update(value);
		}
	}	
};

class ConcreteObserver : public Observer {
	int observerState;
	
	void update(int value) override {
		observerState = value;
		std::cout << "Observer Update with value " << observerState << std::endl;
	}
};

int main() {
	Subject subject;							// Субъект, управляющий состояниями, события происходят в области его компетенций
	ConcreteObserver observer1, observer2;		// Подписчики на события
	
	subject.attach(&observer1);	// Добавим подписчика
	subject.attach(&observer2);

	subject.notify(5);			// Объект изменился и отправил собщение всем подписчикам
	
	subject.detach(&observer2);	// Удаляем из подписчиков observer2
	subject.notify(42);			// Объект изменился и отправил собщение всем подписчикам
	
	return 0;
}
/*
Output:
Observer Update with value 5
Observer Update with value 5
Observer Update with value 42
*/