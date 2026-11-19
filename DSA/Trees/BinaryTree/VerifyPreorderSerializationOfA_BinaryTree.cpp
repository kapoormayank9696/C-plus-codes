// Verify Preorder Serialization of a Binary Tree Algorithm Implementation In C++
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Solution Class
class Solution {
    public:
    // Is Valid Serialization function
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string node;

        int slots = 1;

        while (getline(ss, node, ',')) {
            if (slots <= 0) {
                return false;
            }

            if (node == "#") {
                slots--;
            } else {
                slots++;
            }
        }

        return slots == 0;
    }
};

// Main function
int main() {
    Solution sol;
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << "Preorder Serialization: " << preorder << endl;

    if (sol.isValidSerialization(preorder)) {
        cout << "Valid Serialization: true" << endl;
    }
    else {
        cout << "Valid Serialization: false" << endl;
    }
    return 0;
}
