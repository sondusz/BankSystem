#pragma once
#include <iostream>
#include <string>
using namespace std;

class Validation {
    public:
    
    static bool ValidateName(string name) {
		string pattern = " 0123456789~!@#$%^&*()_+=?<>,.;:";
		for (int i = 0; i < name.size(); i++) {
			if (pattern.find(name[i]) >= 0 && pattern.find(name[i]) <= pattern.size() || name.size() < 5 || name.size() > 20) {
				return false;
			}
		}
		return true;
	}

	static bool ValidatePassword(string password) {
		for (int i = 0; i < password.size(); i++) {
			if (password[i] == ' ' || password.size() < 8 || password.size() > 20) {
				return false;
			}
		}
		return true;
	}

   static bool ValidateBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}

    static bool ValidateSalary(double salary) {
		if (salary < 5000) {
			return false;
		}
		return true;
	}




};

