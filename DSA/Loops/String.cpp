// Count Uppercase, Lowercase, and Other Characters Algorithm Impelemtation In C++
#include<iostream>
#include<cctype>
using namespace std;

// Main function
int main() {
    char str;
    int lowerCount = 0, upperCount = 0, others = 0;

    cout << "\nInput characters: Press CTRL+Z (Windows) or CTRL+D (Linux/Mac) to end input.\n";

    while(cin.get(str)) {

        if(isupper(str)) {
            upperCount++;
        }

        else if(islower(str)) {
            lowerCount++;
        }

        else {
            others++;
        }
    }

    // Displaying the results
    cout << "\nUppercase letters: " << upperCount << endl;
    cout << "Lowercase letters: " << lowerCount << endl;
    cout << "Other characters: " << others << endl;

    return 0;
}

