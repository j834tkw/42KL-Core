#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
	private:
		std::string	target;

	public:
		std::string getTarget() const;
		void	action() const;

		RobotomyRequestForm();
		RobotomyRequestForm(std::string newTarget);
		RobotomyRequestForm(const RobotomyRequestForm &ppf);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &ppf);
		~RobotomyRequestForm();
};

#endif