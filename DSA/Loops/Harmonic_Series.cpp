// Harmonic Series Algorithm Implementation In C++
#include <iostream>
using namespace std;
// Function to calculate the sum of the harmonic series up to n
double harmonicSeries(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        if(i < n) {
            cout<< "1/" << i << " + ";
        }else {
            cout<< "1/" << i;
        }
        sum += 1.0 / i; // Add the reciprocal of i to the sum
    }
    cout<<endl;
    return sum;
}

// Main function
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    double result = harmonicSeries(n);
    cout << "The sum of the harmonic series up to " << n << " is: " << result << endl;
    return 0;
}

