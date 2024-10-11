#include "ASerializer.hpp"
#include <iostream>

int	main(void)
{
	t_data	someData;
	t_data	*someDataPtr;
	t_data	*someDataPtrCheck;

	someData.data_char = 'c';
	someData.data_int = 100;
	someDataPtr = &someData;

	std::cout << "before serialize: " << someDataPtr << std::endl;
	someDataPtrCheck = ASerializer::deserialize(ASerializer::serialize(someDataPtr));
	if (someDataPtr == someDataPtrCheck)
		std::cout << "Conversion OK !" << std::endl;
	else
		std::cout << "Conversion KO !" << std::endl;

	return (0);
}