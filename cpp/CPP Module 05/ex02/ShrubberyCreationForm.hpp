#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	target;

	public:
		std::string getTarget() const;
		void	action() const;

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string newTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm &ppf);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &ppf);
		~ShrubberyCreationForm();
};

#endif