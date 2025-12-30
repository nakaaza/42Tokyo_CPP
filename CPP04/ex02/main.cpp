#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void	brainTest();
static void	deepCopyTest();
static void	set_primary_dog_idea(Dog *dog, int i);
static void	set_primary_cat_idea(Cat *cat, int i);

int main()
{
	brainTest();
	std::cout << std::endl;
	deepCopyTest();
	return 0;
}

static void	set_primary_dog_idea(Dog *dog, int i)
{
	std::string ideas[3] = {"I'm hungry, give me some chicken.", "WALK! WALK! WALK!", "Mooom! Don't! Don't leave me alone!"};
	dog->setIdea(0, ideas[i % 3]);
	return ;
}

static void	set_primary_cat_idea(Cat *cat, int i)
{
	std::string ideas[3] = {"I'm hungry, give me some fish.", "Where's my warm and silent bed?", "You're leaving? That's all fine. Bye."};
	cat->setIdea(0, ideas[i % 3]);
	return ;
}

static void	brainTest()
{
	std::cout << "=== Brain TEST =====================" << std::endl;
	const int size = 10;
	AAnimal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
		{
			Dog* dog = new Dog();
			animals[i] = dog;
			set_primary_dog_idea(dog, i);
		}
		else
		{
			Cat* cat = new Cat();
			animals[i] = cat; 
			set_primary_cat_idea(cat, i);
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			std::cout << "I'm " << i << ", a " << animals[i]->getType() << ". "
					  << dynamic_cast<Dog*>(animals[i])->getIdea(0)
					  << std::endl;
		else
			std::cout << "I'm " << i << ", a " << animals[i]->getType() << ". "
					  << dynamic_cast<Cat*>(animals[i])->getIdea(0)
					  << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];

	return ;
}

static void deepCopyTest()
{
	std::cout << "=== Deep Copy TEST =====================" << std::endl;

	// ---- Dog: copy constructor ----
	std::cout << std::endl
			  << "--- Dog copy constructor test ----------"
			  << std::endl;
	Dog d1;
	d1.setIdea(0, "idea of original dog");
	Dog d2(d1);

	d2.setIdea(0, "idea of copied dog");

	std::cout << "original:\t" << d1.getIdea(0) << std::endl;
	std::cout << "copied:\t\t" << d2.getIdea(0) << std::endl;

	// ---- Dog: copy assignment operator ----
	std::cout << std::endl
			  << "--- Dog copy assignment operator test ----------"
			  << std::endl;
	Dog d3;
	d3 = d1;

	d3.setIdea(0, "idea of copy assigned dog");

	std::cout << "original:\t" << d1.getIdea(0) << std::endl;
	std::cout << "copy assigned:\t" << d3.getIdea(0) << std::endl;

	// ---- Cat: copy constructor ----
	std::cout << std::endl
			  << "--- Cat copy constructor test ----------"
			  << std::endl;
	Cat c1;
	c1.setIdea(0, "idea of original cat");
	Cat c2(c1);

	c2.setIdea(0, "idea of copied cat");

	std::cout << "original:\t" << c1.getIdea(0) << std::endl;
	std::cout << "copied:\t\t" << c2.getIdea(0) << std::endl;

	// ---- Cat: copy assignment operator ----
	std::cout << std::endl
			  << "--- Cat copy assignment operator test ----------"
			  << std::endl;
	Cat c3;
	c3 = c1;

	c3.setIdea(0, "idea of copy assigned cat");

	std::cout << "original:\t" << c1.getIdea(0) << std::endl;
	std::cout << "copy assigned:\t" << c3.getIdea(0) << std::endl;

	std::cout << std::endl;

	return ;
}
