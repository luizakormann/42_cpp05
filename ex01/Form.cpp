#include "Form.hpp"

Form::Form() : _name("Form"), _is_signed(0), _sign_grade(84) _exec_grade(42)
{
}

Form::Form(const std::string &name, const int sign_grade, const int exec_grade) : _name(name), _is_signed(0), _sign_grade(sign_grade) _exec_grade(exec_grade)
{
}

Form::Form(const Form &src) : _name(src._name), _is_signed(src._is_signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
}

Form &Form::operator=(const Form &src)
{
	if (this != src)
	 this->_is_signed = src._is_signed;
	return (*this);
}

Form::~Form()
{
}

const std::string	&Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->is_signed);

}

int	Form::getSignGrade() const
{
	return (this->sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->exec_grade);
}

void	Form::beSigned(const Bureaucrat &bureau)
{
}

const char	*Form::GradeTooHighException::what() const throw()
{
}

const char	*Form::GradeTooLowException::what() const throw()
{
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
}

