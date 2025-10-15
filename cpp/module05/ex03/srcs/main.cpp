/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:00:00 by analba-s          #+#    #+#             */
/*   Updated: 2025/10/15 19:01:40 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Intern.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

void printSeparator(const std::string& title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "TEST: " << title << std::endl;
	std::cout << "========================================" << std::endl;
}

void test1_shrubberyCreation()
{
	printSeparator("Shrubbery Creation - Success");
	AForm* scf = NULL;
	try {
		Intern someRandom;
		scf = someRandom.makeForm("shrubbery creation", "home");
		Bureaucrat rodolfo("Rodolfo", 2);
		std::cout << rodolfo.getName() << ", bureaucrat grade " << rodolfo.getGrade() << std::endl;
		rodolfo.improveGrade();
		std::cout << rodolfo.getName() << ", bureaucrat grade " << rodolfo.getGrade() << std::endl;
		rodolfo.signForm(*scf);
		rodolfo.executeForm(*scf);
		delete scf;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (scf)
			delete scf;
	}
}

void test2_robotomyRequest()
{
	printSeparator("Robotomy Request - Success");
	AForm* rrf = NULL;
	try {
		Intern someRandom;
		rrf = someRandom.makeForm("robotomy request", "Bender");
		Bureaucrat carlos("carlos", 2);
		std::cout << carlos.getName() << ", bureaucrat grade " << carlos.getGrade() << std::endl;
		carlos.improveGrade();
		std::cout << carlos.getName() << ", bureaucrat grade " << carlos.getGrade() << std::endl;
		carlos.signForm(*rrf);
		carlos.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (rrf)
			delete rrf;
	}
}

void test3_presidentialPardon()
{
	printSeparator("Presidential Pardon - Success");
	AForm* ppf = NULL;
	try {
		Intern someRandom;
		ppf = someRandom.makeForm("presidential pardon", "Arthur Dent");
		Bureaucrat ana("Ana", 2);
		std::cout << ana.getName() << ", bureaucrat grade " << ana.getGrade() << std::endl;
		ana.improveGrade();
		std::cout << ana.getName() << ", bureaucrat grade " << ana.getGrade() << std::endl;
		ana.signForm(*ppf);
		ana.executeForm(*ppf);
		delete ppf;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (ppf)
			delete ppf;
	}
}

void test4_unknownForm()
{
	printSeparator("Unknown Form - Exception Test");
	AForm* form = NULL;
	try {
		Intern someRandom;
		form = someRandom.makeForm("presidential exploit", "target");
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		if (form)
			delete form;
	}
}

void test5_gradeTooLowToSign()
{
	printSeparator("Grade Too Low to Sign");
	AForm* ppf = NULL;
	try {
		Intern someRandom;
		ppf = someRandom.makeForm("presidential pardon", "target");
		Bureaucrat potter("Potter", 26);
		std::cout << potter.getName() << ", bureaucrat grade " << potter.getGrade() << std::endl;
		potter.signForm(*ppf);
		potter.executeForm(*ppf);
		delete ppf;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (ppf)
			delete ppf;
	}
}

void test6_gradeTooLowToExecute()
{
	printSeparator("Grade Too Low to Execute");
	AForm* scf = NULL;
	try {
		Intern someRandom;
		scf = someRandom.makeForm("shrubbery creation", "garden");
		Bureaucrat lowGrade("LowGrade", 145);
		Bureaucrat highGrade("HighGrade", 1);
		std::cout << lowGrade.getName() << ", bureaucrat grade " << lowGrade.getGrade() << std::endl;
		highGrade.signForm(*scf); // High grade signs
		lowGrade.executeForm(*scf); // Low grade tries to execute
		delete scf;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (scf)
			delete scf;
	}
}

void test7_executeUnsignedForm()
{
	printSeparator("Execute Unsigned Form");
	AForm* rrf = NULL;
	try {
		Intern someRandom;
		rrf = someRandom.makeForm("robotomy request", "target");
		Bureaucrat boss("Boss", 1);
		std::cout << boss.getName() << ", bureaucrat grade " << boss.getGrade() << std::endl;
		// Try to execute without signing
		boss.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (rrf)
			delete rrf;
	}
}

void test8_copyIntern()
{
	printSeparator("Copy Intern Test");
	AForm* form1 = NULL;
	AForm* form2 = NULL;
	try {
		Intern intern1;
		Intern intern2(intern1); // Copy constructor
		Intern intern3;
		intern3 = intern1; // Assignment operator
		
		form1 = intern2.makeForm("shrubbery creation", "copy_test1");
		form2 = intern3.makeForm("robotomy request", "copy_test2");
		
		std::cout << "Forms created successfully from copied interns" << std::endl;
		
		delete form1;
		delete form2;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (form1)
			delete form1;
		if (form2)
			delete form2;
	}
}

void test9_multipleFormsFromSameIntern()
{
	printSeparator("Multiple Forms from Same Intern");
	AForm* forms[3] = {NULL, NULL, NULL};
	try {
		Intern intern;
		forms[0] = intern.makeForm("shrubbery creation", "target1");
		forms[1] = intern.makeForm("robotomy request", "target2");
		forms[2] = intern.makeForm("presidential pardon", "target3");
		
		std::cout << "All three forms created successfully" << std::endl;
		
		for (int i = 0; i < 3; i++) {
			if (forms[i])
				delete forms[i];
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		for (int i = 0; i < 3; i++) {
			if (forms[i])
				delete forms[i];
		}
	}
}

void test10_extremeGrades()
{
	printSeparator("Extreme Grade Values");
	AForm* ppf = NULL;
	try {
		Intern intern;
		ppf = intern.makeForm("presidential pardon", "extreme_test");
		
		// Test with grade 150 (lowest)
		Bureaucrat lowest("Lowest", 150);
		std::cout << lowest.getName() << ", grade " << lowest.getGrade() << std::endl;
		lowest.signForm(*ppf); // Should fail
		
		// Test with grade 1 (highest)
		Bureaucrat highest("Highest", 1);
		std::cout << highest.getName() << ", grade " << highest.getGrade() << std::endl;
		highest.signForm(*ppf);
		highest.executeForm(*ppf);
		
		delete ppf;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (ppf)
			delete ppf;
	}
}

void test11_emptyStrings()
{
	printSeparator("Empty String Tests");
	AForm* form = NULL;
	try {
		Intern intern;
		form = intern.makeForm("", "target"); // Empty form name
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (form)
			delete form;
	}
}

void test12_caseInsensitiveTest()
{
	printSeparator("Case Sensitive Test");
	AForm* form = NULL;
	try {
		Intern intern;
		form = intern.makeForm("SHRUBBERY CREATION", "target"); // Wrong case
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		if (form)
			delete form;
	}
}

int main(void)
{
	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║   COMPREHENSIVE TEST SUITE - EX03     ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;

	// Success tests
	test1_shrubberyCreation();
	test2_robotomyRequest();
	test3_presidentialPardon();
	
	// Exception tests
	test4_unknownForm();
	test5_gradeTooLowToSign();
	test6_gradeTooLowToExecute();
	test7_executeUnsignedForm();
	
	// Edge case tests
	test8_copyIntern();
	test9_multipleFormsFromSameIntern();
	test10_extremeGrades();
	test11_emptyStrings();
	test12_caseInsensitiveTest();

	std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║        ALL TESTS COMPLETED            ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝\n" << std::endl;
	
	return 0;
}
