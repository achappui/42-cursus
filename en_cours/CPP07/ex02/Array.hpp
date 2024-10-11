#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
private:
	T		*m_array;
	size_t	m_size;
public:
	Array()
		:	m_array(new T[0]()),
			m_size(0)
	{}

	Array(unsigned n)
		:	m_array(new T[n]()),
			m_size(static_cast<size_t>(n))
	{}

	Array(const Array& other)
		:	m_array(new T[other.m_size]()),
			m_size(other.m_size)
	{
		for (size_t i = 0; i < other.m_size; i++)
			m_array[i] = other.m_array[i];
	}

	Array&	operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] m_array;
			m_array = new T[other.m_size]();
			for (size_t i = 0; i < other.m_size; i++)
				m_array[i] = other.m_array[i];
			m_size = other.m_size;
		}
		return (*this);
	}

	T&	operator[](size_t index)
	{
		if (m_size == 0 || index >= m_size)
			throw std::out_of_range("Index out of range");
		return (m_array[index]);
	}

	const T&	operator[](size_t index) const
	{
		if (m_size == 0 || index >= m_size)
			throw std::out_of_range("Index out of range");
		return (m_array[index]);
	}

	~Array() {delete[] m_array;}

	size_t	size(void) const {return (m_size);}
};

#endif
