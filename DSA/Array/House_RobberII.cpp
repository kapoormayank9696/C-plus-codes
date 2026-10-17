// House Robber II Algorithm Implementation In C++
#include <iostream>
#include <algorithm>
using namespace std;

// Function to help the Rob Method
int checkRob(int nums[], int start, int end) {
    int prev1 = 0;
    int prev2 = 0;

    for (int i = start; i < end; i++) {
        int num = nums[i];
        int current = max(prev1, num + prev2);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

// Function To Perform The House Robber
int rob(int nums[],int n) {
    if(n == 1) {
        return nums[0];
    }
    return max(checkRob(nums,0,n-1),checkRob(nums,1,n));
}

// Main function
int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Print an array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "House robbery Maximum : " << rob(nums, n) << endl;
    return 0;
}
