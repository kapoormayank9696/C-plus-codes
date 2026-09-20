#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void quickSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);

            quickSort(nums, low, pi - 1);
            quickSort(nums, pi + 1, high);
        }
    }

    int partition(vector<int> &nums, int low, int high) {
        int pivort = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivort) {
                i++;

                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }

        i++;

        int temp = nums[i];
        nums[i] = nums[high];
        nums[high] = temp;

        return i;
    }

    int findContentChildren(vector<int> &g, vector<int> &s) {

        quickSort(g, 0, g.size() - 1);
        quickSort(s, 0, s.size() - 1);

        int child = 0;
        int cookies = 0;

        while (child < g.size() && cookies < s.size()) {

            if (s[cookies] >= g[child]) {
                child++;
            }

            cookies++;
        }

        return child;
    }
};

int main() {

    Solution solution;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    int result = solution.findContentChildren(g, s);

    cout << "Number of content children: " << result << endl;

    return 0;
}