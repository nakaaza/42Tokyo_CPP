#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	if (!ptr)
		return (uintptr_t) NULL;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	if (raw == (uintptr_t)NULL)
		return (Data*) NULL;
	return reinterpret_cast<Data*>(raw);
}
