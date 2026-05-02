// Integers Divisible By 9 Between 100 And 200
#include <iostream>
using namespace std;
// Function to print integers divisible by 9 between 100 and 200
void printDivisibleBy9() {
    int sum=0;
    cout << "Integers divisible by 9 between 100 and 200:" << endl;
    for (int i = 100; i <= 200; i++) {
        if (i % 9 == 0) {
            sum=sum+i;
            cout << i << " ";
        }
    }
    cout << endl;
    cout<<"The sum : "<<sum;
}

// Main function
int main() {
    printDivisibleBy9();
    return 0;
}

