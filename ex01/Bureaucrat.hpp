#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"


class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		static void			validateGrade(int grade);

	
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		const std::string	&getName() const;
		int					getGrade() const;

		void		downGrade();
		void		upGrade();

		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		void	signForm();
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureau);

#endif