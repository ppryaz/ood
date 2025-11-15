// Decorator - используется для добавления в компонент, какого-либо дополнительного поведения без необходимости менять код основного класса 
// В данном примере основной класс - ConcreteComponent
#include <iostream>

// Step 1: Define the Component interface
class Component {
public:
    virtual ~Component() {}
    virtual void operation() const = 0;
};
// Step 2: Create concrete component - Define базовое поведение
class ConcreteComponent : public Component {
public:
    void operation() const {
        std::cout << "Basic Operation\n";	// Реализация базового функционала
    }
};
// Step 3: Create Base Decorator
class Decorator : public Component {
protected:
    Component* component;
public:
    Decorator(Component* comp) : component(comp) {}
    virtual void operation() const {
        component->operation();
    }
};
// Concrete Decorator A - декоратор для компонента
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}
    void operation() const {
        Decorator::operation();
        std::cout << "Decorator A Operation\n";		// Добавляется операция после основной работы класса 
    }
};
// Concrete Decorator B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}
    void operation() const {
        Decorator::operation();
        std::cout << "Decorator B Operation\n"; 	// // Добавляется операция к уже установленым в рамках экземпляра класса
    }
};

int main() {
    Component* simple = new ConcreteComponent();
	Component* decorator = new Decorator(simple);					// Базовые операции
    Component* decoratorA = new ConcreteDecoratorA(simple);			// Базовые операции
    Component* decoratorB = new ConcreteDecoratorB(decoratorA);		// Базовые, + A Decorator + B Decorator
	Component* decoratorBS = new ConcreteDecoratorB(simple);		// Базовые  + B Decorator
	simple->operation();
	decoratorA->operation();
    decoratorB->operation();
	decoratorBS->operation();
    delete simple;
    delete decoratorA;
    delete decoratorB;
    return 0;
}