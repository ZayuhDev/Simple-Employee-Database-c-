#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <vector>
#include <string>

struct Employee
{
	std::string name;
	int age;
};

class EmployeeManager
{
public:
	void viewAllEmployees();
	void addEmployee(const std::string name, int age);
	void removeEmployee(const std::string name);
	void addEmployeeMenu();
	void removeEmployeeMenu();
	void menu();

private:
	std::vector<Employee> employees;
};

#endif