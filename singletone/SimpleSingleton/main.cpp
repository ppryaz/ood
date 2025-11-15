// Pattern Singletone

#include <iostream>

class Singleton {
private:
	int data {0};
	static Singleton *instance_ptr;
	
	Singleton() {}

public:
	static Singleton* getInstance() {
		if (!instance_ptr) instance_ptr = new Singleton();
		return instance_ptr;
	}
	Singleton(const Singleton&) = delete;
	~Singleton() {
		delete instance_ptr;
		instance_ptr = nullptr;
	}
	void setData(int d) { data = d; }
	int getData() { return data; }
};

Singleton* Singleton::instance_ptr = nullptr;

int main() {
	Singleton* ptr = Singleton::getInstance();
	Singleton *ptr2 = Singleton::getInstance();
	
	ptr->setData(1);

    std::cout << ptr << " " << ptr2 << std::endl;
    std::cout << ptr2->getData() << " " << ptr->getData() << std::endl;
 
    delete ptr;

	return 0;
}
