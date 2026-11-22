// Length of Last Word Algorithm Implementation In C++
#include <iostream>
#include <string>
using namespace std;

// Solution Class
class Solution {
    public:

    // Length Of Last Word
    int lengthOfLastWord(string s) {
        int length = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                length++;
            }
            else {
                if (length > 0)
                    return length;
            }
        }
        return length;
    }
};

// Main function
int main() {
    string s = "Hello World";
    cout << "String s: " << s << endl;
    Solution sol;
    cout << "Length Of Last Word From A String: " << sol.lengthOfLastWord(s) << endl;

    return 0;
}
