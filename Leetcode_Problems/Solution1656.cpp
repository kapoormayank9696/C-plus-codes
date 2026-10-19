// LeetCode Problem 1656 : Design an Ordered Stream
#include <bits/stdc++.h>
using namespace std;

// Solution class
class OrderedStream {
    public:
    // Define Dynamic Array
    vector<string> arr;
    int ptr = 1;

    // Parameterized Constructor
    OrderedStream(int n) {
        arr.resize(n + 1);
    }

    // Insert Function into dynamic array
    vector<string> insert(int idKey, string value) {
        arr[idKey] = value;
        vector<string> ans;

        while (ptr < arr.size() && arr[ptr] != "") {
            ans.push_back(arr[ptr]);
            ptr++;
        }

        return ans;
    }

    // Display
    void display() {
        for (int i = 0; i < arr.size(); i++) {
            cout <<arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    int n = 5;
    OrderedStream solution(n);

    cout << "Insert the elements into dynamic array: " << endl;
    
    for (int i = 0; i < n; i++) {
        int idKey;
        string value;

        cin >> idKey >> value;

        solution.insert(idKey, value);
    }
    solution.display();

    return 0;
}
