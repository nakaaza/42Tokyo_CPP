#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	test_animal(Animal* animal)
{
	std::cout << "Type: " << animal->getType() << std::endl;
	std::cout << "Sound: ";
	animal->makeSound();
}

int main()
{
	std::cout << "=== Default constructor test ===============" << std::endl;
	Animal* meta1 = new Animal();
	Animal* dog1 = new Dog();
	Animal* cat1 = new Cat();
	test_animal(meta1);
	test_animal(dog1);
	test_animal(cat1);

	std::cout << std::endl;

	std::cout << "--- Wrong version ---" << std::endl;
	WrongAnimal*	w_meta = new WrongAnimal();
	WrongAnimal*	w_cat = new WrongCat();
	std::cout << "Type: " << w_meta->getType() << std::endl;
	std::cout << "Sound: ";
	w_meta->makeSound();
	std::cout << "Type: " << w_cat->getType() << std::endl;
	std::cout << "Sound: ";
	w_cat->makeSound();
	std::cout << std::endl;
	
	delete w_meta;
	delete w_cat;

	std::cout << "=== Copy constructor test ===============" << std::endl;
	Animal* meta2 = new Animal(*meta1);
	Animal* dog2 = new Dog(*dynamic_cast<Dog*>(dog1));
	Animal* cat2 = new Cat(*dynamic_cast<Cat*>(cat1));
	test_animal(meta2);
	test_animal(dog2);
	test_animal(cat2);
	std::cout << std::endl;

	std::cout << "=== Copy assignment operator test ===============" << std::endl;
	Animal* meta3 = new Animal();
	Animal* dog3 = new Dog();
	Animal* cat3 = new Cat();
	*meta3 = *meta2;
	*dog3 = *dog2;
	*cat3 = *cat2;
	test_animal(meta3);
	test_animal(dog3);
	test_animal(cat3);
	std::cout << std::endl;

	delete meta1;
	delete dog1;
	delete cat1;
	delete meta2;
	delete dog2;
	delete cat2;
	delete meta3;
	delete dog3;
	delete cat3;


	return 0;
}
