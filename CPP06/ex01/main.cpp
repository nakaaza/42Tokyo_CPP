#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data*	A = new Data ;
	A->index = 0;
	A->name = "HOGE";
	std::cout << "A\t= " << A << std::endl;
	
	uintptr_t raw = Serializer::serialize(A);
	std::cout << "raw\t= " 
			  << std::hex << "0x" << raw
			  << std::dec << std::endl;

	Data* B = Serializer::deserialize(raw);
	std::cout << "B\t= " << B << std::endl;

	std::cout << "*A = { index: " << A->index << ", name: " << A->name << " }" << std::endl;
	std::cout << "*B = { index: " << B->index << ", name: " << B->name << " }" << std::endl;

	delete A;
	return 0;
}
