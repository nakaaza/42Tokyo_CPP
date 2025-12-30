#ifndef BRAIN_HPP
# define BRAIN_HPP

# define IDEA_COUNT 100

# include <string>

class Brain {

private:
	std::string	ideas[IDEA_COUNT];

public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &rhs);
	~Brain();

	void		set_idea(size_t idx, std::string idea);
	std::string	get_idea(size_t idx) const;
};

#endif // BRAIN_HPP
