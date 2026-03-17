// LoopII Algorithm Implementation In C++
#include<iostream>
#include<cmath>
using namespace std;

// Main function
int main() {
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        int sum=a;
        for(int j=0;j<c;j++) {
            sum=sum+pow(2,j)*b;
            cout<<sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}

