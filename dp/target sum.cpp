class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
            unordered_map<int, int> dp;
            dp[0]=1;
            for(int num: nums){
                  unordered_map<int, int> nextdp;
                  for(auto &[sum, count]: dp){
                      nextdp[sum+num]+=count;
                      nextdp[sum-num]+=count;
                  }
                  dp=nextdp;
            }
            return dp[target];
    }
};  
