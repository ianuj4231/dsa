class Solution {
public:
    int rob2(const vector<int> &nums){
         if(nums.size()==0){
                return 0;
            }
            if(nums.size()==1){
                return nums[0];
            }
            if(nums.size()==2){
                return max(nums[0], nums[1]);
            }
            int n=nums.size();
            vector<int> dp(n);
            dp[0]=nums[0];
            dp[1]=max(nums[0], nums[1]);
            for(int i=2;i<n;i++){
                  dp[i]= max(dp[i-2]  + nums[i] , dp[i-1]  );
            }
            return dp[n-1];
    }
  
    int rob(vector<int>& nums) {
                    if(nums.size()==1){
                        return nums[0];
                    }
                    int v1=rob2(vector<int>(nums.begin(), nums.end()-1  ));       
                    int v2=rob2(vector<int>(nums.begin()+1, nums.end()  ));       
                    return max(v1, v2);
    }
  
};
