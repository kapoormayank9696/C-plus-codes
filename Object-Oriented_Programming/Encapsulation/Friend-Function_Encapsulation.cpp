//Friend function only use in the topic of Encapuslation not in Inheritance , Polymorphism or Abstraction
#include<iostream>
using namespace std;
class Customer {
private:
    string name;
    double balance;
public:
//Setter function
    Customer(string n, double b) {
        name = n;
        balance = b;
    }
//Friend function work as the getter function
    // Friend function declaration
    friend void showBalance(Customer c);
};

// Friend function definition (outside class)
void showBalance(Customer c) {
    cout << "Customer Name: " << c.name << endl;
    cout << "Account Balance: $" << c.balance << endl;
}

int main() {
    Customer c1("Maya", 15000.50);

    // Calling friend function
    showBalance(c1);
    return 0;
}

