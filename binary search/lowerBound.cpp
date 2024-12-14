#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1; // To store the index of the lower bound
    while (left <= right) {
        int mid = left + (right - left) / 2; // To avoid overflow
        if (arr[mid] >= target) {
            result = mid;  // Potential lower bound
            right = mid - 1; // Move to the left half
        } else {
            left = mid + 1; // Move to the right half
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, 3, 5, 7, 9, 9};
    int target = 4;

    int lbIndex = lowerBound(arr, target);
    if (lbIndex != -1)
        cout << "Lower bound of " << target << " is at index: " << lbIndex << ", value: " << arr[lbIndex] << endl;
    else
        cout << "No lower bound found for " << target << endl;

    return 0;
}


// use example 1 6 6 6 6 and use target 5.
