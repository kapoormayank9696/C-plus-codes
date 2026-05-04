// Highest Common Factor (HCF) or Greatest Common Divisor (GCD) of two numbers
#include <iostream>
using namespace std;
// Function to calculate HCF using Euclidean algorithm
int hcf(int a, int b) {
    int hcf = 1;
    int k = (a < b) ? a : b; 
    for(int i=1;i<=k;i++) {
        if(a%i == 0 && b%i == 0) {
            hcf = i;
        }
    }
    return hcf;
}

// Main function
int main() {
    int num1, num2;
    cout << "Input 1st number for HCF:";
    cin >> num1;
    cout << "Input 2nd number for HCF:";
    cin >> num2;
    int result = hcf(num1, num2);
    cout << "The HCF of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}

