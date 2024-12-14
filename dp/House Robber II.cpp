
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]; // Edge case for a single element
        
        // Lambda function to compute the maximum robbed value
        auto robin = [&](const vector<int>& nums2) -> int {
            int n = nums2.size();
            if (n == 0) return 0; // Handle case when the subarray is empty
            if (n == 1) return nums2[0]; // Only one house
            
            vector<int> dp(n);
            dp[0] = nums2[0];
            dp[1] = max(nums2[0], nums2[1]);
            
            for (int i = 2; i < n; i++) {
                dp[i] = max(dp[i - 2] + nums2[i], dp[i - 1]);
            }
            
            return dp[n - 1]; // Return the maximum amount that can be robbed
        };

        // Case 1: Rob houses from index 0 to n-2
        int start0 = robin(vector<int>(nums.begin(), nums.end() - 1));
        
        // Case 2: Rob houses from index 1 to n-1
        int start1 = robin(vector<int>(nums.begin() + 1, nums.end()));

        // Return the maximum of the two cases
        return max(start0, start1);
    }
};
