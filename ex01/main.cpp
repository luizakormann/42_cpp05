#include "Bureaucrat.hpp"
#include <Form.hpp>
#include <iostream>

static void validConstructionTest()
{
	std::cout << "\n=== Basic construction test ===\n" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 42);

		std::cout << bob << std::endl;
		std::cout << "Name: " << bob.getName() << std::endl;
		std::cout << "Grade: " << bob.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void defaultConstructorTest()
{
	std::cout << "\n=== Default construction test ===\n" << std::endl;

	try
	{
		Bureaucrat bureau;

		std::cout << bureau << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void boundaryConstructionTest()
{
	std::cout << "\n=== Limits construction test ===\n" << std::endl;

	try
	{
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);

		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void upDownGradeTest()
{
	std::cout << "\n=== upGrade() downGrade() tests ===\n" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 42);

		std::cout << bob << std::endl;
		bob.upGrade();
		std::cout << "After upGrade():   " << bob << std::endl;
		bob.downGrade();
		std::cout << "After downGrade(): " << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void invalidHighGradeTest()
{
	std::cout << "\n=== GradeTooHigh test ===\n" << std::endl;

	try
	{
		Bureaucrat high("High", 0);

		std::cout << high << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void invalidLowGradeTest()
{
	std::cout << "\n=== GradeTooLow test ===\n" << std::endl;

	try
	{
		Bureaucrat low("Low", 151);

		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void upGradeLimitTest()
{
	std::cout << "\n=== invalid upGrade() test ===\n" << std::endl;

	Bureaucrat top("Top", 1);

	try
	{
		std::cout << top << std::endl;
		top.upGrade();
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "After exception: " << top << std::endl;
}

static void downGradeLimitTest()
{
	std::cout << "\n=== invalid downGrade() test ===\n" << std::endl;

	Bureaucrat bottom("Bottom", 150);

	try
	{
		std::cout << bottom << std::endl;
		bottom.downGrade();
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "After exception: " << bottom << std::endl;
}

static void copyConstructorTest()
{
	std::cout << "\n=== copy constructor test ===\n" << std::endl;

	try
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;

		copy.upGrade();
		std::cout << "\n--- After copy.upGrade() ---\n" << std::endl;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void assignmentOperatorTest()
{
	std::cout << "\n=== operator= test ===\n" << std::endl;

	try
	{
		Bureaucrat alice("Alice", 10);
		Bureaucrat bob("Bob", 100);

		std::cout << "Before:  " << alice << " | " << bob << std::endl;
		bob = alice;
		std::cout << "After: " << alice << " | " << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	validConstructionTest();
	defaultConstructorTest();
	boundaryConstructionTest();
	upDownGradeTest();
	invalidHighGradeTest();
	invalidLowGradeTest();
	upGradeLimitTest();
	downGradeLimitTest();
	copyConstructorTest();
	assignmentOperatorTest();

	std::cout << "\n=== The End ===" << std::endl;
	return 0;
}