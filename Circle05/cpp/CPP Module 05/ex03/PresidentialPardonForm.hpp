#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm: public AForm
{
	private:
		std::string	target;

	public:
		std::string getTarget() const;
		void	action() const;
		// static AForm *createFormPP(std::string target);

		PresidentialPardonForm();
		PresidentialPardonForm(std::string newTarget);
		PresidentialPardonForm(const PresidentialPardonForm &ppf);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &ppf);
		~PresidentialPardonForm();
};

#endif