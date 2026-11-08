// Find the Distance Value Between Two Arrays Algorithm Implementation In C++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if the number is valid based on the distance value
bool isValid(int num, vector<int> &arr2, int d) {
    for (int i = 0; i < arr2.size(); i++) {
        if (abs(num - arr2[i]) <= d) {
            return false;
        }
    }
    return true;
}

// Function to find the distance value between two arrays
int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int count = 0;
    for(int num:arr1) {
        if(isValid(num, arr2, d)) {
            count++;
        }
    }
    return count;
}

// Main Function
int main() {
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;
    cout << "The distance value between the two arrays is: " << findTheDistanceValue(arr1, arr2, d) << endl;
    return 0;
}
