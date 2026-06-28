// Design HashSet Algorithm Implementation In C++
#include<iostream>
#include<unordered_set>
using namespace std;

// Class Solution Of HashSet
class MyHashSet {
    public:

    unordered_set<int> set;
    
    // Constructor
    MyHashSet() {
    }
    
    // Add
    void add(int key) {
        set.insert(key);
    }
    
    // Remove
    void remove(int key) {
        set.erase(key);
    }
    
    // Check whether the key exists
    bool contains(int key) {
        return set.find(key) != set.end();
    }

    // Display
    string display() {
        string result = "{ ";
    
        for (int value : set) {
            result += to_string(value) + " ";
        }

        result += "}";
        return result;
    }
};

// Main function
int main() {
    // Create Object The HashSet
    MyHashSet hashSet;

    int nums[] = {1, 2, 1, 3, 2, 2, 2, 2};

    for (int num : nums) {
        hashSet.add(num);
    }

    cout << "\nDisplay HashSet : " << hashSet.display() << endl;

    cout << "HashSet Contains 1 : " << hashSet.contains(1) << endl;
    cout << "HashSet Contains 3 : " << hashSet.contains(3) << endl;

    hashSet.add(2);
    cout << "HashSet Contains 2 : " << hashSet.contains(2) << endl;

    hashSet.remove(2);
    cout << "HashSet Contains 2 : " << hashSet.contains(2) << endl;

    cout << "After Removing The HashSet : " << hashSet.display() << endl;

    return 0;
}
