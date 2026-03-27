// LeetCode Problem 204: Count Primes
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> isPrime(n, true);

        // 0 and 1 are not prime
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Number of primes less than " << n << " is: " 
         << obj.countPrimes(n) << endl;
    return 0;
}
