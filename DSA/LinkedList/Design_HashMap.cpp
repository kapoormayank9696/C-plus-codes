// Design HashMap Algorithm Implementation In C++
#include<iostream>
#include <unordered_map>
using namespace std;

class MyHashMap {
    public:
    unordered_map<int, int> map;

    public:
    // Insert Operation
    void put(int key, int value) {
        map[key] = value;
    }

    // Get Operation
    int get(int key) {
        if (map.find(key) != map.end())
            return map[key];
        return -1;
    }

    // Remove Operation
    void remove(int key) {
        map.erase(key);
    }

    // Print Operation
    void display() {
        cout << "{ ";
        for (auto &pair : map) {
            cout << pair.first << "=" << pair.second << " ";
        }
        cout << "}" << endl;
    }
};

// Main function
int main() {
    // Create Object Of MyHashMap Class
    MyHashMap hashMap;

    int nums[] = {1, 1, 2, 2, 1, 3, 2, 1, 2, 2, 2};

    for (int num : nums) {
        hashMap.put(num, num);
    }

    cout << "Print Hash Map: ";
    hashMap.display();

    cout << "Get The Value From Hash Map: " << hashMap.get(2) << endl;

    hashMap.remove(2);

    cout << "After Removing Key 2: ";
    hashMap.display();
    return 0;
}

