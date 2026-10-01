#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureau"), _grade(42)
{	
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::downGrade()
{
	validateGrade(_grade + 1);
	_grade++;
}

void	Bureaucrat::upGrade()
{
	validateGrade(_grade - 1);
	_grade--;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (highest possible grade is 1)");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (lowest possible grade is 150)");
}


std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureau)
{
	out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
	return (out);
}