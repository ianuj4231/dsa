/*

cost to reach 1 + cost to jump from 1 \
					 MINN
cost to reach 2 + cost to jump from 2 /   

cost to reach n-1 + cost to jump from n-1 
cost to reach n-2 + cst to jump from n-2

arr[0] = 0, min cost to reach  1st step 
 arr[1]= 0, 
arr[2]= min(arr[0] + cost[0]


*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
            int n = nums.size();
            int prev2=0, prev1=0;
            for(int i=2;i<=n;i++){
                   int curr=min(prev1+ nums[i-1], prev2+ nums[i-2]);
                   prev2=prev1;
                   prev1=curr;
            }
            return prev1;
    }
};
