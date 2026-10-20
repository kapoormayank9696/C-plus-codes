// Longest Uploaded Prefix Algorithm Implementation In C++
#include<iostream>
#include<vector>
using namespace std;

// LUPrefix Class
class LUPrefix {

    // Public Specifier
    public:

    vector<bool> uploaded;
    int longestPrefix;

    // Parameterized Constructor
    LUPrefix(int n) {
        uploaded.resize(n+1,false);
        longestPrefix = 0;
    }

    // Insert
    void upload(int video) {
        uploaded[video] = true;
    }

    // Function to return length of uploaded elements
    int longest() {
        while(longestPrefix + 1 < uploaded.size() && uploaded[longestPrefix+1]) {
            longestPrefix++;
        }
        return longestPrefix;
    }

    // Display
    void printUploaded() {
        cout << "Uploaded videos: ";
        for (int i = 1; i < uploaded.size(); i++) {
            if (uploaded[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    int n = 3;
    LUPrefix luPrefix(n);

    luPrefix.upload(1);
    luPrefix.upload(2);
    luPrefix.upload(3);

    cout << "Total count elements into Longest Prefix : "  << luPrefix.longest() << endl;

    cout << "Display the LUPrefix: ";
    luPrefix.printUploaded();
    return 0;
}
