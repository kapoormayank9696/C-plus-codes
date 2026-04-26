// Average Of N Numbers Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Main function
int main(){
    int n;
    cout<<"Enter the number of natural numbers to average: ";
    cin>>n;
    
    int sum = 0;
    cout<<"\nThe natural numbers up to "<<n<<" terms are :";
    for(int i=1; i<=n; i++){
        cout<<i<<" "; // Printing the ith natural number
        sum += i; // Adding the ith natural number
    }
    cout<<"\nThe sum of the first "<<n<<" natural numbers is: "<<sum<<endl;
    double average = static_cast<double>(sum) / n; // Calculating the average
    cout<<"\nThe average of the first "<<n<<" natural numbers is: "<<average<<endl;
    
    return 0;
}


