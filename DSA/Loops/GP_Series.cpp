// G.P. Series Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Function to perform G.P. Series
void gpSeries(int n1,int n,int r) {
    cout<<"The numbers for the G.P. series: ";

    double sum=0,result=n1;
    for(int i=1;i<=n;i++) {
        cout<<result<<" ";
        sum=sum+result;
        result=result*r;
    }

    cout<<endl;
    cout<<"The Sum of the G.P. series : "<<sum<<endl;
}

// Main function
int main() {
    int n1,n,r;

    cout<<"Input the first number of the G.P. series: ";
    cin>>n1;

    cout<<"Input the number of terms in the G.P. series: ";
    cin>>n;

    cout<<"Input the common ratio of G.P. series: ";
    cin>>r;

    gpSeries(n1,n,r);

    return 0;
}

