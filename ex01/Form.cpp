#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _is_signed(false), _sign_grade(84), _exec_grade(42)
{
}

Form::Form(const std::string &name, const int sign_grade, const int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	validateGrade(sign_grade);
	validateGrade(exec_grade);
}

Form::Form(const Form &src) : _name(src._name), _is_signed(src._is_signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	 this->_is_signed = src._is_signed;
	return (*this);
}

Form::~Form()
{
}

const std::string	&Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_is_signed);

}

int	Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void	Form::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void	Form::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_is_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (highest possible grade is 1)");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getSignGrade()
		<< ", grade to execute: " << form.getExecGrade() << ".";
	return (out);
}

