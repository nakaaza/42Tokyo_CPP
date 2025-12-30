#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {

private:
	const static int	idea_count = 100;
	std::string			ideas[idea_count];

public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &rhs);
	~Brain();

	void		set_idea(size_t idx, std::string idea);
	std::string	get_idea(size_t idx) const;
};

#endif // BRAIN_HPP
