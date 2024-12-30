#include "EmployeeManager.h"
#include <iostream>
#include <string>

void clearConsole()
{
	system("cls");
}

void EmployeeManager::viewAllEmployees()
{
	clearConsole();
	std::cout << "-----THE EMPLOYEE DATABASE-----\n";

	// loop thru the vector of employees
	for (size_t i = 0; i < employees.size(); i++)
	{
		std::cout << "[" << i + 1 << "]" << " " << employees[i].name << "\n";
	}

	std::cout << "\nPress Enter to return to the menu...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	this->menu();
}

void EmployeeManager::addEmployee(const std::string name, int age)
{
	Employee newEmployee{ name, age };
	employees.push_back(newEmployee);
	this, viewAllEmployees();

	std::cout << "Press enter to return to the menu.";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	this->menu();
}

void EmployeeManager::removeEmployee(const std::string name)
{
	// early return if the employees vector is empty.
	if (employees.size() == 0)
	{
		std::cout << "There are currently no employees in the database. \n";
		return;
	}

	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees[i].name == name)
		{
			// print to the console that the employee has been removed.
			std::cout << employees[i].name << " has been removed from the employee database. \n";

			// Remove employee from vector / database.
			employees.erase(employees.begin() + i);

			// show updated employee list to show that the employee has been removed
			std::cout << "Press enter to return to the menu.";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			this->menu();
			return;
		}
	}
}

void EmployeeManager::addEmployeeMenu()
{
	clearConsole();
	std::cout << "----ADD NEW EMPLOYEES-----\n";

	std::string name{};
	int age{};

	std::cout << "New employee's name: ";
	std::cin >> name;

	std::cout << "New employee's age: ";
	std::cin >> age;

	addEmployee(name, age);
}

void EmployeeManager::removeEmployeeMenu()
{
	clearConsole();
	std::cout << "----REMOVE EMPLOYEE-----\n";

	std::string name{};
	int age{};

	std::cout << "employee's name: ";
	std::cin >> name;

	this->removeEmployee(name);
}

void EmployeeManager::menu()
{
	clearConsole();

	std::cout << "-----WELCOME TO ZAY'S EMPLOYEE DATABASE!-----\n";

	std::cout << "[1] view employee database\n";
	std::cout << "[2] add a new employee to the database\n";
	std::cout << "[3] remove an existing employee from the database\n";

	int userChoiceInput{};

	std::cout << "Please choose what you would like to do: ";
	std::cin >> userChoiceInput;

	switch (userChoiceInput)
	{
	case 1:
		viewAllEmployees();
		break;
	case 2:
		addEmployeeMenu();
		break;
	case 3:
		removeEmployeeMenu();
	}
}