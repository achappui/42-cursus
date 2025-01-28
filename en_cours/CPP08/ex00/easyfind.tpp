template<typename T>
typename T::const_iterator	easyfind(const T& container, int integer)
{
	typename T::const_iterator	it;

	it = container.begin();
	while (it != container.end())
	{
		if (*it == integer)
			return (it);
		it++;
	}
	return (it);
}
