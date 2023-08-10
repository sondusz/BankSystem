#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Validation.h"

class Person {
protected:
	//Attributes
	string name;
	int id;
	string password;
public:
	//Constructors:
	Person() {
		this->name = " ";
		this->id = 0;
		this->password = " ";
	}
	Person(string name, int id, string password) {
		setName(name);
		setPassword(password);
		setId(id);
	}
   //Setters:
	void setName(string name) {
		if (Validation::ValidateName(name))
			this->name = name;
	}
    void setPassword(string password) {
		if (Validation::ValidatePassword(password)) {
			this->password = password;
		}
	}
	void setId(int id) {
		this->id = id;
	}
    //Getters:
	string getName(){
        return this->name ;
    }
    string getPassword(){
        return this->password;
    }
    int getId(){
        return this->id;
    }
    //Method
    void display(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"Password: "<<this->password<<endl;
        cout<<"Id: "<<this->id<<endl;
    }
};