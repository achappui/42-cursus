#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int	random = std::rand() % 3;
	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "ptr Type A !" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "ptr Type B !" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "ptr Type C !" << std::endl;
	else
		std::cout << "ptr Type unknown !" << std::endl;
}

void	identify(Base& p)
{
    try
	{
        dynamic_cast<A&>(p);
        std::cout << "ref Type A !" << std::endl;
        return;
    }
	catch (const std::bad_cast& e) {}
    try
	{
        dynamic_cast<B&>(p);
        std::cout << "ref Type B !" << std::endl;
        return;
    }
	catch (const std::bad_cast& e) {}
    try
	{
        dynamic_cast<C&>(p);
        std::cout << "ref Type C !" << std::endl;
        return;
    }
	catch (const std::bad_cast& e) {}
	std::cout << "ref Type unknown" << std::endl;
}

int	main(void)
{
	Base	*ptr = generate();
	Base&	ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
	return (0);
}