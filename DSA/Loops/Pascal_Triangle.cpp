// Pascal's Triangle Algorithm Implementation In C++
#include <iostream>
#include <vector>
using namespace std;
// Function to generate Pascal's Triangle
void printPascalsTriangle(int n) {
    int c=1;
    for(int i=0;i<n;i++) {
        for(int space=1;space<=n-i;space++)
            cout<<"  ";
        for(int j=0;j<=i;j++) {
            if(j==0 || i==0) {
                c=1;
            }
            else {
                c=c*(i-j+1)/j;
            }
            cout<<c<<" ";
        }
        cout<<endl;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> n;
    printPascalsTriangle(n);
    return 0;
}
