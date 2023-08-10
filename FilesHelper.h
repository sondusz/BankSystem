#pragma once
#include <iostream>
#include <fstream>
#include "Admin.h"
#include "Parser.h"
using namespace std;

class FilesHelper{
    private:
	static void saveLast(string fileName, int id) {
		ofstream file;
		file.open(fileName);
		file << id;
		file.close();
	}
    public:

	//ClientLastID
	static int getLast(string fileName) {
		ifstream file;
		file.open(fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c) {

		int id = getLast("ClientLastId.txt");
		fstream file;
		file.open("Clients.txt", ios::app);
		file << id + 1 << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << "\n";
		file.close();
		saveLast("ClientLastId.txt", id + 1);
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		int id = getLast(lastIdFile);
		fstream file;
		file.open(fileName, ios::app);
		file << id + 1 << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << "\n";
		file.close();
		saveLast(lastIdFile, id + 1);
	}
	static void getClients() {
		string line;
		ifstream file;
		file.open("Clients.txt");
		while (getline(file, line)) {
			Client c = Parser::parseToClient(line);
			allClients.push_back(c);
		}
		file.close();
	}
	static void getEmployees() {
		string line;
		ifstream file;
		file.open("Employees.txt");
		while (getline(file, line)) {
			Employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}
	static void getAdmins() {
		string line;
		ifstream file;
		file.open("Admins.txt");
		while (getline(file, line)) {
			Admin a = Parser::parseToAdmin(line);
			allAdmins.push_back(a);
		}
		file.close();
	}
	static void clearFile(string fileName, string lastIdFile) {
		fstream file1, file2;
		file1.open(fileName, ios::out, ios::trunc);
		file1.close();
		file2.open(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}


};
