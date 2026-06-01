#include<iostream>
using namespace std;
class Car : public Vehicle{
    public:
    float mileage;
    car(string x,string y,int z,float m): Vehicle(x,y,z){
        this->mileage = m;
    }
    void details(){
        cout<<"Car name : "<<this->name<<" Brand of car : "<<this->brand<<" Year of car : "<<this->year<<" Mileage of car : "<<this->mileage<<endl<<endl;
    }
};