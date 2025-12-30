#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Default constructor test ===============" << std::endl;
	Animal* meta1 = new Animal();
	Animal* dog1 = new Dog();
	Animal* cat1 = new Cat();
	std::cout << dog1->getType() << " " << std::endl;
	std::cout << cat1->getType() << " " << std::endl;
	dog1->makeSound();
	cat1->makeSound();
	meta1->makeSound();

	WrongAnimal*	w_meta = new WrongAnimal();
	WrongAnimal*	w_cat = new WrongCat();
	std::cout << w_cat->getType() << " " << std::endl;
	w_cat->makeSound();
	w_meta->makeSound();
	std::cout << std::endl;
	
	delete w_meta;
	delete w_cat;

	std::cout << "=== Copy constructor test ===============" << std::endl;
	Animal* meta2 = new Animal(*meta1);
	Animal* dog2 = new Dog(*dynamic_cast<Dog*>(dog1));
	Animal* cat2 = new Cat(*dynamic_cast<Cat*>(cat1));
	std::cout << dog2->getType() << " " << std::endl;
	std::cout << cat2->getType() << " " << std::endl;
	dog2->makeSound();
	cat2->makeSound();
	meta2->makeSound();
	std::cout << std::endl;

	std::cout << "=== Copy assignment operator test ===============" << std::endl;
	Animal* meta3 = new Animal();
	Animal* dog3 = new Dog();
	Animal* cat3 = new Cat();
	*meta3 = *meta2;
	*dog3 = *dog2;
	*cat3 = *cat2;
	std::cout << dog3->getType() << " " << std::endl;
	std::cout << cat3->getType() << " " << std::endl;
	dog3->makeSound();
	cat3->makeSound();
	meta3->makeSound();
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
