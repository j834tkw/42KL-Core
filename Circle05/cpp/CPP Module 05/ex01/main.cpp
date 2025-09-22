#include "Bureaucrat.hpp"
#include "Form.hpp"


using std::cout;
using std::endl;

int main(void)
{
	// ---------------Can use these stuff----------------//
	// Bureaucrat B1("Amogus", 1);
	// Bureaucrat B2("Christopher Columbus", 75);

	// Form F1("Contract to abstain from venting", 150, 150);
	// Form F2("Agreement for the resurrection of Hitler with the nazi army and Qin Shi Huang with his teracotta army", 100, 100);
	// Form F3("Legalisation of slave trading", 1, 1);

	try
	{
		Bureaucrat B1("Amogus", 1);
		Form F1("Contract to abstain from venting", 150, 150);
		B1.signForm(F1);
	}
	catch (const Form::GradeTooLowException& err)
	{
		cout << err.what() << endl;
	}

	cout << endl;

	try
	{
		Bureaucrat B2("Christopher Columbus", 75);
		Form F3("Legalisation of slave trading", 1, 1);
		B2.signForm(F3);
	}
	catch (const Form::GradeTooLowException& err)
	{
		cout << err.what() << endl;
	}

	cout << endl;

	try
	{
		Bureaucrat B1("Amogus", 1);
		Bureaucrat B2("Christopher Columbus", 75);
		Form F2("Agreement for the resurrection of Hitler with the nazi army and Qin Shi Huang with his teracotta army", 100, 100);
		B1.signForm(F2);
		B2.signForm(F2);
	}
	catch (const Form::GradeTooLowException& err)
	{
		cout << err.what() << endl;
	}

	return (0);
}
