#include <iostream>
#include <vector>
#include <algorithm> // For sort

void removeDuplicates(std::vector<int>& nums) {
    // Sort the array to make duplicates adjacent
    std::sort(nums.begin(), nums.end());

    // Use two pointers
    int n = nums.size();
    if (n == 0) return; // If the array is empty, do nothing

    int j = 0; // Points to the position of the next unique element

    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[j]) {
            // Move unique elements forward
            ++j;
            nums[j] = nums[i];
        }
    }

    // Resize the vector to keep only unique elements
    nums.resize(j + 1);
}

int main() {
    std::vector<int> nums = {4, 2, 4, 1, 2, 5, 1, 6};

    // Remove duplicates
    removeDuplicates(nums);

    // Display the result
    std::cout << "Array after removing duplicates: ";
    for (const int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
