#ifndef __EMPLOYEE_CPP
#define __EMPLOYEE_CPP

#include <string>

class Employee{

	Employee();	

	Employee(string first, string last, int age);

	~Employee();
	
	public:

		bool setFirstName(string first);
		bool setLastName(string last);
		bool setAge(int age);
		
		string getFirstName();
		string getLastName();
		string getAge();

		print();

	private:

		string firstName;
		string LastName;
		int Age;
};

#endif
