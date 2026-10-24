// Design Ride Sharing System Algorithm Implementation In C++
#include <iostream>
#include <queue>
using namespace std;

// Class RideSharing system
class RideSharingSystem {
    queue<int> queueRider;
    queue<int> queueDriver;

    // Public Specifier 
    public:

    // Parameterized Constructor
    RideSharingSystem() {}

    // Add Rider
    void addRider(int riderId) {
        queueRider.push(riderId);
    }

    // Add Driver
    void addDriver(int driverId) {
        queueDriver.push(driverId);
    }

    // Match Driver With Rider
    vector<int> matchDriverWithRider() {
        if (queueRider.empty() || queueDriver.empty()){
            return {-1, -1};
        }

        int rider = queueRider.front();
        queueRider.pop();

        int driver = queueDriver.front();
        queueDriver.pop();

        return {driver, rider};
    }

    // Cancel the rider
    void cancelRider(int riderId) {
        queue<int> temp;

        while (!queueRider.empty()) {
            int rider = queueRider.front();
            queueRider.pop();

            if (rider != riderId) {
                temp.push(rider);
            }
        }

        queueRider = temp;
    }

    // Display Riders
    void displayRiders() {
        queue<int> temp = queueRider;

        cout << "Riders: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    // Display Drivers
    void displayDrivers() {
        queue<int> temp = queueDriver;

        cout << "Drivers: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// Main function
int main() {
    RideSharingSystem obj;

    obj.addRider(3);
    obj.addRider(1);

    obj.addDriver(2);
    obj.addDriver(5);

    obj.displayRiders();
    obj.displayDrivers();

    vector<int> result = obj.matchDriverWithRider();

    cout << "Matched Driver: " << result[0] << endl;
    cout << "Matched Rider: " << result[1] << endl;

    obj.displayRiders();
    obj.displayDrivers();

    obj.cancelRider(1);

    cout << "\nAfter cancelling Rider 1:" << endl;
    obj.displayRiders();

    return 0;
}
