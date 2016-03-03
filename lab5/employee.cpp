#include <string>
#include "employee.hpp"


using namespace std;
Employee::Employee(){

	std::cout << "This employee is blank!" << endl;

}

Employee::Employee(string first,std: string last, int age){
	cout << "making employee... " << endl;
	setFirstname(first);
	setLastName(last);
	setAge(age);
	cout << "employee made" << endl;
}

Employee::~Employee(){

	cout << "employee killed" << endl;

}

bool Employee::setFirstName(string first){
	
	if(first != null){
		if(first != firstName){
			firstName = first;
			return true;
		}
	
		else{
			cout << "That is their first name." << endl;
			return false;
		}
	}
	return false;

}

bool Employee::setLastName(string last){

	if (last != null){
		if(last != lastName{
			lastName = last;
			return true;
		} 

		else{
                	cout << "That is their last name." << endl;
        		return false;
		}	
	}

	return false;
}

bool Employee::setAge(int age){
	
	if(age == null){
		return false;
	}
	
	if(age > 0){
		if(age ! = Age){
			Age = age;
			return true;
		}
		else{
			cout << "That is their age." << endl;
			return false;
		}	
	
	else{
		cout << "No one is the young." << endl;
		return false;
	}
	return false;
}

string Employee::getFirstName(){

	return firstName;
	
}

string Emloyee::getLastName(){

	return lastName;

}

int Employee::getAge(){

	return Age;

}

viod Employee::print(){
	cout << firstName << " " << lastName << " " << Age << endl
}
