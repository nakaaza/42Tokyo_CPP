#include "Identifier.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "iostream"
#include "cstdlib"
#include "ctime"

Base*	generate(void)
{
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}

	Base*	base;
	switch (std::rand() % 3) {
		case 0:
			base = new A();
			break ;
		case 1:
			base = new B();
			break ;
		case 2:
			base = new C();
			break ;
		default:
			base = NULL;
	}
	return base;
}

void	identify(Base* p)
{
	if (!p)
		return ;
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";

}

void	identify(Base& p)
{
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A";
		return ;
	} catch (std::exception& e) {}
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B";
		return ;
	} catch (std::exception& e) {}
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "C";
		return ;
	} catch (std::exception& e) {}
}
