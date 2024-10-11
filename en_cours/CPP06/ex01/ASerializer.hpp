#ifndef ASERIALIZER_HPP
# define ASERIALIZER_HPP

# include <string>

typedef struct s_data
{
	int		data_int;
	char	data_char;
}	t_data;

class ASerializer
{

public:
	static uintptr_t	serialize(t_data *ptr);
	static t_data		*deserialize(uintptr_t raw);

	ASerializer();
	ASerializer(const ASerializer& other);
	ASerializer&	operator=(const ASerializer& other);
	virtual ~ASerializer() = 0;
};


#endif