//  A.P. Series Algorithm Implementation In C++
#include<iostream>
using namespace std;
// Function to perform the A.P. Series
void apSeries(int n,int m,int diff) {
    int sum=0,term=n;
    for(int i=n;i<=m;i=i+1) {
        cout<<term<<" ";
        sum=sum+term;
        term=term+diff;
    }
    cout << endl;
    cout << "Sum of the series: " << sum << endl;
}

// Main function
int main() {
    int n,m,diff;
    cout<<"Input the starting number of the A.P. series: ";
    cin>>n;
    cout<<"Input the number of items for the A.P. series: ";
    cin>>m;
    cout<<"Input the common difference of A.P. series: ";
    cin>>diff;
    cout << "The A.P. series is: " << endl;
    apSeries(n,m,diff);
    return 0;
}

