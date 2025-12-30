#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal*	w_meta = new WrongAnimal();
	const WrongAnimal*	w_cat = new WrongCat();
	std::cout << w_cat->getType() << " " << std::endl;
	w_cat->makeSound();
	w_meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete w_meta;
	delete w_cat;

	return 0;
}
