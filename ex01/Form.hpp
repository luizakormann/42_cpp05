#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;

		static void			validateGrade(int grade);

	public:
		Form();
		Form(const std::string &name, const int sign_grade, const int exec_grade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		void	beSigned(const Bureaucrat &bureau);

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

};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif