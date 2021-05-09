#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void Talk() const {}; /* it is not a pure virtual method */
    // virtual void Talk() const = 0; /* it is a pure virtual method */

    virtual ~Animal() {
    }
};

class Dog : public Animal {
public:
    Dog(){};

    void Talk() const {
        cout << "Gav\n";
    }
};

class Cat : public Animal {
public:
    Cat(){};

    void Talk() const {
        cout << "Myau\n";
    }
};

int main() {

    const Dog dog = Dog();
    const Cat cat = Cat();

    // sizeof(Animal*) is the same for all objects  -> uses child.Talk method
    vector<const Animal*> animals = { &dog, &cat };

    for (const auto& animal : animals) {
        animal->Talk(); // Gav, Myau
    }

    // sizeof(Dog) may be != sizeof(Cat) -> uses Animal.Talk method
    vector<Animal> animals_obj = { dog, cat }; // here will be error in case of pure virt method

    for (const auto& animal : animals_obj) {
        animal.Talk(); // silence, silence
    }

    return 0;
}
