// Floyd's Triangle Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to print Floyd's Triangle
void printFloydsTriangle(int n) {
    int p,q;
    for(int i=1;i<=n;i++) {
        if(i%2==0) {
            p=0;
            q=1;
        }
        else {
            p=1;
            q=0;
        }
        for(int j=1;j<=i;j++) {
            if(j%2==0) {
                cout<<p<<" ";
            }
            else {
                cout<<q<<" ";
            }
        }
        cout<<endl;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the number of rows for Floyd's Triangle: ";
    cin >> n;
    printFloydsTriangle(n);
    return 0;
}