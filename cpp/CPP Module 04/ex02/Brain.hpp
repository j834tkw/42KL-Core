#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];

	public:
		void setIdea(std::string idea, int index);
		std::string getIdea(int index);

		Brain(void);
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		~Brain(void);
};

#endif