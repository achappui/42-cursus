#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename ARRAY, typename LEN, typename FUNC>
void	iter(ARRAY& array, LEN len, const FUNC& func)
{
	for (LEN i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void	emptify(T& a)
{
	a.clear();
	std::cout << "EMPTY ";
}

#endif
