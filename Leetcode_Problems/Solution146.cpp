// LeetCode Problem 146: LRU Cache
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    public:
    int capacity;

    // Stores key-value pairs in LRU to MRU order
    list<pair<int, int>> cache;

    // Maps key to its position in the list
    unordered_map<int, list<pair<int, int>>::iterator> map;

    // Parameterized Constructor
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    // Get Method
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }

        // Get the existing node
        auto it = map[key];

        // Move recently used node to the end
        cache.splice(cache.end(), cache, it);

        return it->second;
    }

    // Put Method
    void put(int key, int value) {
        if (capacity == 0)
            return;

        // If key already exists, update its value
        if (map.find(key) != map.end()) {
            auto it = map[key];
            it->second = value;

            // Move updated key to MRU position
            cache.splice(cache.end(), cache, it);
            return;
        }

        // If capacity is full, remove LRU element
        if (cache.size() == capacity) {
            int firstKey = cache.front().first;

            cache.pop_front();
            map.erase(firstKey);
        }

        // Insert new key at MRU position
        cache.push_back({key, value});
        map[key] = prev(cache.end());
    }

    // Display Function
    void display() {
        for (auto it : cache) {
            cout << "[" << it.first << ":" << it.second << "] ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache lruCache(3);

    lruCache.put(1, 10);
    lruCache.put(2, 20);
    lruCache.put(3, 30);

    lruCache.display();

    lruCache.get(1);

    lruCache.put(4, 40);

    lruCache.display();

    cout << "Get key 2: " << lruCache.get(2) << endl;

    return 0;
}
