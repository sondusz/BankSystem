#pragma once
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include "AdminManager.h"
using namespace std;

class Screens{
private:
	static void bankName() {
		cout << "\t\t@@       @@   @@@@@@@      #######   ########  ####     ##  ##   ##\n";
		cout << "\t\t@@   @   @@   @@           ##    ##  ##    ##  ## ##    ##  ##  ##\n";
		cout << "\t\t@@  @@@  @@   @@@@@@@      #######   ########  ##  ##   ##  ## #\n";
		cout << "\t\t@@ @@ @@ @@   @@           ##    ##  ##    ##  ##   ##  ##  ##  ##\n";
		cout << "\t\t@@@     @@@   @@@@@@@      #######   ##    ##  ##    ####   ##   ##\n";
	}
	static void welcome() {
		system("Color 3f");
		cout << "\n\n\n\n\n\n\t    ##       ##   #######   ##      #######  ########    ####    ####   #######\n";
		cout << "\t    ##   #   ##   ##        ##      ##       ##    ##    ##  #  #  ##   ##\n";
		cout << "\t    ##  ###  ##   ######    ##      ##       ##    ##    ##   ##   ##   #######\n";
		cout << "\t    ## ## ## ##   ##        ##      ##       ##    ##    ##        ##   ##\n";
		cout << "\t    ###     ###   #######   ######  #######  ########    ##        ##   #######\n\n\n";
		bankName();
		Sleep(5000);
		system("cls");
		system("Color 0f");
	}
	static void loginOptions() {
		cout << "(1) Admin" << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Client\n" << endl;
		cout << "Login as: ";
	}
	static int loginAs() {
		loginOptions();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invalid(int c) {
		system("cls");
		cout << "Incorrect id or password.\n" << endl;
		loginScreen(c);
	}
	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}
	static void loginScreen(int c) {
		int choice = c, id;
		string pass;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter password: ";
		cin >> pass;
		switch (choice)
		{
		case 1:
			if (AdminManager::login(id, pass) != NULL) { 
				while (AdminManager::adminOptions(AdminManager::login(id, pass)) != false);
				logout();
			}
			else invalid(1);
			break;
		case 2:
			if (EmployeeManager::login(id, pass) != NULL) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
				logout();
			}
			else invalid(2);
			break;
		case 3:
			if (ClientManager::login(id, pass) != NULL)
			{
				while (ClientManager::clientOptions(ClientManager::login(id, pass)) != false);
				logout();
			}
			else invalid(3);
			break;
		default:
			system("cls");
			loginOptions();
		}
	}
public:
	static void runApp() {
		FileManager::getAllData();
		welcome();
		loginScreen(loginAs());
	}
};