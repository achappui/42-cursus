template<typename T>
size_t	getNumberOfDigits(T num)
{
	size_t	digits = 0;

	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}
