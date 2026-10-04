#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void validFormTest()
{
	std::cout << "\n=== Valid Form test ===\n" << std::endl;

	try
	{
		Form tax("Tax", 50, 25);

		std::cout << "--- return operator<< ---" << std::endl;
		std::cout << tax << std::endl;
		std::cout << "--- return getters ---" << std::endl;
		std::cout << "Name: " << tax.getName() << std::endl;
		std::cout << "Signed: " << tax.getIsSigned() << std::endl;
		std::cout << "Sign grade: " << tax.getSignGrade() << std::endl;
		std::cout << "Exec grade: " << tax.getExecGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void defaultFormTest()
{
	std::cout << "\n=== Default constructor test ===\n" << std::endl;

	try
	{
		Form def;

		std::cout << def << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void boundaryFormTest()
{
	std::cout << "\n=== Limits construction test ===\n" << std::endl;

	try
	{
		Form top("Top", 1, 1);
		Form bottom("Bottom", 150, 150);

		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void invalidHighFormTest()
{
	std::cout << "\n=== Invalid Form test (GradeTooHigh) ===\n" << std::endl;

	try
	{
		Form badSign("BadSign", 0, 50);

		std::cout << badSign << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (sign 0): " << e.what() << std::endl;
	}

	try
	{
		Form badExec("BadExec", 50, 0);

		std::cout << badExec << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (exec 0): " << e.what() << std::endl;
	}
}

static void invalidLowFormTest()
{
	std::cout << "\n=== Invalid Form test (GradeTooLow) ===\n" << std::endl;

	try
	{
		Form badSign("BadSign", 151, 50);

		std::cout << badSign << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (sign 151): " << e.what() << std::endl;
	}

	try
	{
		Form badExec("BadExec", 50, 151);

		std::cout << badExec << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (exec 151): " << e.what() << std::endl;
	}
}

static void beSignedSuccessTest()
{
	std::cout << "\n=== beSigned() test: good grade ===\n" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 10);
		Form contract("Contract", 50, 25);

		std::cout << "Before:  " << contract << std::endl;
		contract.beSigned(boss);
		std::cout << "After: " << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void beSignedExactGradeTest()
{
	std::cout << "\n=== beSigned(): limit test ===\n" << std::endl;

	try
	{
		Bureaucrat exact("Exact", 50);
		Form contract("Contract", 50, 25);

		contract.beSigned(exact);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void beSignedFailTest()
{
	std::cout << "\n=== beSigned(): bad grade ===\n" << std::endl;

	Bureaucrat intern("Intern", 100);
	Form contract("Contract", 50, 25);

	try
	{
		contract.beSigned(intern);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "After exception: " << contract << std::endl;
}

static void signFormSuccessTest()
{
	std::cout << "\n=== signForm(): OK ===\n" << std::endl;

	Bureaucrat boss("Boss", 10);
	Form contract("Contract", 50, 25);

	boss.signForm(contract);
	std::cout << contract << std::endl;
}

static void signFormFailTest()
{
	std::cout << "\n=== signForm(): KO ===\n" << std::endl;

	Bureaucrat intern("Intern", 100);
	Form contract("Contract", 50, 25);

	intern.signForm(contract);
	std::cout << contract << std::endl;
}

static void signFormExactGradeTest()
{
	std::cout << "\n=== signForm(): limit test) ===\n" << std::endl;

	Bureaucrat lowest("Lowest", 150);
	Form easy("Easy", 150, 150);

	lowest.signForm(easy);
	std::cout << easy << std::endl;
}

static void formCopyTest()
{
	std::cout << "\n=== copy tests ===\n" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		Form original("Original", 50, 25);
		Form copy(original);
		Form assigned("Assigned", 100, 100);

		boss.signForm(original);
		assigned = original;

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << " (copy before signed)" << std::endl;
		std::cout << "Assigned: " << assigned << " signed copied" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	validFormTest();
	defaultFormTest();
	boundaryFormTest();
	invalidHighFormTest();
	invalidLowFormTest();
	beSignedSuccessTest();
	beSignedExactGradeTest();
	beSignedFailTest();
	signFormSuccessTest();
	signFormFailTest();
	signFormExactGradeTest();
	formCopyTest();

	std::cout << "\n=== The End ===" << std::endl;
	return 0;
}