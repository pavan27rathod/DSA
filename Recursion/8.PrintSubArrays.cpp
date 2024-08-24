#include<iostream>
#include<vector>

using namespace std;

void printSubArrays(vector<int>& nums, int start, int end) {
    // Base case: if end index reaches the size of the array, return
    if (end == nums.size())
        return;

    // Print the current subarray
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Recursive call: move the end index to the right
    printSubArrays(nums, start, end + 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    // Loop over each possible starting point
    for (int i = 0; i < nums.size(); i++) {
        // Print all subarrays starting with index 'i'
        printSubArrays(nums, i, i);
    }

    return 0;
}
