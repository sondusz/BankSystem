#pragma once
#include "Person.h";

class Client : public Person{
private:
    //Attributes:
    double balance;
public:
    //Constructors:
    Client() : Person(){
        this->balance = 0;
    }
    Client(string name , string password, int id, double balance) : Person(name, password, id){
        setBalance(balance)
    }
    //Setters:
    void setBalance(double balance){
        if(Validation::ValidateBalance(balance))
        this->balance=balance;
    }
    //Getters:
    double getBalance(){
        return this->balance;
    }
    //Methods:
    void display(){
        Person::display();
        cout<<"Balance: "<<this->balance<<endl;
    }
    void withdrow(double amount){
        if(amount<=this->balance && amount >0){
            this->balance-=amount ;
            cout << "\n Successful Transaction. \n";
        }
        else cout << "\nAmount Exceeded.\n";
    }
    void deposit(double amount) {
		if(amount > 0)
			this->balance += amount;
		cout << "\nSuccessful transaction.\n";
	}
    void transferTo(double amount, Client& recipient) {
		if (amount <= balance) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
	}
    void checkBalance() {
		cout << "Balance: " << this->balance << endl;
	}

};