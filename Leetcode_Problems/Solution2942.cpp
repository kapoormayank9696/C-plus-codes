// LeetCode Problem Find Words Containing Character
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function of find word containing into strng array
vector<int> findWordsContaining(vector<string> &words, char x) {
    vector<int> arr;
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] == x) {
                arr.push_back(i);
                break;
            }
        }
    }
    return arr;
}

// Main function
int main() {
    vector<string> words = {"leet", "code"};
    char x = 'e';
    cout << "Print String Array: [";
    for (int i = 0; i < words.size(); i++) {
        if (i > 0)
            cout << ",";
        cout << words[i];
    }
    cout << "]" << endl;

    vector<int> arr = findWordsContaining(words, x);
    cout << "Print where target is find from string array: [";
    for (int i = 0; i < arr.size(); i++) {
        if (i > 0)
            cout << ",";
        cout << arr[i];
    }
    cout << "]" << endl;
    return 0;
}
