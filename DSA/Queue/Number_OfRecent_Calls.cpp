// Number of Recent Calls Algorithm Implementation In C++
#include <iostream>
#include <queue>
using namespace std;

// Class Of Stack
class RecentCounter {
    queue<int> q;

    // Public Access Specifier
    public:

    // Parameterized Constructor
    RecentCounter(){}

    // Ping Operation
    int ping(int t) {
        q.push(t);

        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }

    // Display Operation
    void display() {
        queue<int> temp = q;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

// Main function
int main() {
    RecentCounter obj;

    cout << obj.ping(1) << endl;
    cout << obj.ping(100) << endl;
    cout << obj.ping(3001) << endl;
    cout << obj.ping(3002) << endl;

    cout << "Recent timestamps: ";
    obj.display();
    return 0;
}
