#include "ASerializer.hpp"
#include <iostream>

uintptr_t	ASerializer::serialize(t_data *ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "serialize: " << raw << std::endl;
	return (raw);
}

t_data		*ASerializer::deserialize(uintptr_t raw)
{
	t_data	*ptr;

	ptr = reinterpret_cast<t_data*>(raw);
	std::cout << "deserialize: " << ptr << std::endl;
	return (ptr);
}

ASerializer::ASerializer()
{}

ASerializer::ASerializer(const ASerializer& other)
{
	(void)other;
}

ASerializer&	ASerializer::operator=(const ASerializer& other)
{
	(void)other;
	return (*this);
}
