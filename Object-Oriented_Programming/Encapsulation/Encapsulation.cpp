// C++ program to demonstrate Encapsulation
#include<iostream>
using namespace std;

// Base class
class Encapsulation{
    private: //Data members are private
    string name;
    int pin;
    int balance;
    public:
    //Setter function of the Encapuslation class
    Encapuslation(string nam,int pini,int bala){
        this->name = nam;
        this->pin = pini;
        this->balance = bala;
    }
    void details(){
        cout<<"Name : "<<this->name<<endl;
        cout<<"Pin : "<<this->pin<<endl;
        cout<<"Balance : $"<<this->balance<<endl;
    }
    void deposit(int amount){
        this->balance = this->balance + amount;
        cout<<"Sucessfully deposit $"<<amount<<endl;
        cout<<"Avaliable balance is $"<<this->balance<<endl;
    }
    void withdrawal(int amount,int pin){
        if(this->pin == pin){
            if(this->balance >= amount){
                this->balance = this->balance - amount;
                cout<<"Sucessfully withdrawal $"<<endl;
                cout<<"Available balance is $"<<this->balance<<endl;
            }
            else{
                cout<<"Insufficent balance"<<endl;
            }
        }
        else{
            cout<<"Invalid pin"<<endl;
        }
    }
    void balanceCheck(int pin){
        if(this->pin == pin){
            cout<<"Availabe balance is $"<<this->balance<<endl;
        }
        else{
            cout<<"Invalid pin"<<endl;
        }
    }
    int temp = this->pin;
    void changepin(int pin){
        if(this->pin == pin){
            cout<<"Enter new pin : ";
            int newpin;
            cin>>newpin;
            int k=0;
            if(this->pin != 0){
                int r =this->pin%10;
                k++;
            }
            if(k==4){
                this->pin = newpin;
                cout<<"Sucessfully pin changed"<<endl;
            }else{
                cout<<"Pin must have 4 digit"<<endl;
            }
        }else{
            cout<<"Invalid pin"<<endl;
        }
    }
};

// Main function
int main(){
    // Dynamic memory allocation of the Encapsulation class
    Encapsulation* user1 = new Encapsulation("John",8928,854790);
    user1->details();
            
    //Deposit the money in ATM
    user1->deposit(5000);
    
    //Withdrawal the money from ATM
    user1->withdrawal(50000,8928);
    
    //Print the balance with wrong and right pin
    user1->balanceCheck(8928);    //Change the pin with wrong and right pin
    user1->changepin(8928);
    
    //Print new Pin
    // user1->newpin();
    return 0;
}