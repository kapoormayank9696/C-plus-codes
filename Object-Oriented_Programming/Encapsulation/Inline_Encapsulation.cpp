// C++ program to demonstrate Encapsulation by Inline function
#include<iostream>
#include<string>
using namespace std;

// Base class
class Atm{
    private: //Data members are declare private
    string name;
    int pin;
    float balance;
    //Setter function of the Atm class
    public:
    inline Atm(string n,int p,float b){
        this->name = n;
        this->pin = p;
        this->balance = b;
    }
    //Getter function of the Atm class
    inline void getAtmData(){
        cout<<"Name : "<<name<<endl;
        cout<<"Pin : "<<pin<<endl;
        cout<<"Balance : "<<balance<<endl<<endl;
    }
    
    //Function to deposit money
    void deposit(float amount){
        this->balance = this->balance + amount;
        cout<<"Amount Deposited Successfully!"<<endl;
    }
    void withdrawal(float money ,int p){
        if(this->pin == p){
            if(money <= this->balance){
                this->balance = this->balance - money;
                cout<<"Please collect your cash!"<<endl;
            }
            else{
                cout<<"Insifficient Blanace!"<<endl;
            }
        }
        else{
            cout<<"Invalid Pin!"<<endl;
        }
    }
};

// Main function
int main(){
    // Creating object of Atm class
    Atm* atm = new Atm("John",9689,1635.50f);
    atm->getAtmData();
    atm->deposit(500.0f);
    atm->getAtmData();
    atm->withdrawal(200.0f,9689);
    atm->getAtmData();
    return 0;
}

