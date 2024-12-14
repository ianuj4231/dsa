class Solution {
public:
    int rob(vector<int>& nums) {
          vector<int> dp(nums.size());
          int n=nums.size();
        //   dp[0]=nums[0];
        //   dp[1]=max(nums[0],nums[1]);
          
          int prev1=max(nums[0],nums[1]);
          int prev2=nums[0];
          for(int i=2;i<n;i++){
            //  dp[i]=max(nums[i]+dp[i-2], dp[i-1] ); 
             int curr=max(nums[i]+ prev2, prev1);
             prev2 = prev1;
             prev1=curr;
          }
        //   return dp[n-1];
        return prev1;
    }
};
