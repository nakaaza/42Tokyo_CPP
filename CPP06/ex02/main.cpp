#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identifier.hpp"
#include <iostream>

int	main(void)
{
	Base* b1 = generate();
	Base* b2 = generate();
	Base* b3 = generate();

	std::cout << "b1 is a ";
	identify(b1);
	std::cout << std::endl;
	std::cout << "b2 is a ";
	identify(b2);
	std::cout << std::endl;
	std::cout << "b3 is a ";
	identify(b3);
	std::cout << std::endl;

	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "a is a ";
	identify(a);
	std::cout << std::endl;
	std::cout << "b is a ";
	identify(b);
	std::cout << std::endl;
	std::cout << "c is a ";
	identify(c);
	std::cout << std::endl;

	std::cout << "a is a ";
	identify(*a);
	std::cout << std::endl;
	std::cout << "b is a ";
	identify(*b);
	std::cout << std::endl;
	std::cout << "c is a ";
	identify(*c);
	std::cout << std::endl;
	
	delete a;
	delete b;
	delete c;

}
