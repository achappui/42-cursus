#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
	std::string	m_name;
public:
	Zombie();
	Zombie(const Zombie& other);
	Zombie&	operator=(const Zombie& other);
	~Zombie();
	void	announce(void);
	void	renameZombie(std::string newName);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif