// Sum of Two Primes Algorithms Implementation In C++
#include<iostream>
using namespace std;
// Function to check the number is prime or not
bool isPrime(int temp) {
    if(temp < 2) {
        return false;
    }
    for(int i=2;i<=temp/2;i++) {
        if(temp%i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find the perfect number
void primes(int n) {
    bool found = false;
    int temp1,temp2;
    for(int i=2;i<=n/2;i++) {
        temp1=i;
        temp2=n-i;
        if(isPrime(temp1) && isPrime(temp2)) {
            cout<<n<<" = "<<temp1<<" + "<<temp2<<endl;
            found=true;
        }
    }
    if (!found) {
        cout << "No combination of two prime numbers found.";
    }
}

// Main function
int main() {
    int n;
    cout<<"Input a positive integer: ";
    cin>>n;
    primes(n);
    return 0;
}

