// Alternate Sum Series Algorithm Implementation In C++
#include <iostream>
#include <cmath>
using namespace std;

int alternateSumSeries(int x, int n) {
    int sum = 0, ctr, k;
    for (int i = 1; i <= n; i++) {
        ctr = (2 * i - 1);
        if (i % 2 == 0) {
            k = (int)pow(x, ctr);
        } else {
            k = -(int)pow(x, ctr);
        }
        cout << k << endl;
        sum += k;
    }
    return sum;
}

// Main function
int main() {
    int x, n;

    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = alternateSumSeries(x, n);
    cout << "Final Sum = " << abs(result) << endl;

    return 0;
}
