class Solution {
public:
    int maxArea(vector<int>& nums) {
          int n=nums.size();
          int right=n-1;
          int left=0;
          int maxx=INT_MIN;
          while(left< right){
            // dont re-declare maxx inside
             maxx=max(maxx, (right-left)*min(nums[left], nums[right])  );
            if(nums[left]<nums[right]){
                left++;
            }
            else {
                right--;
            }
          }
          return maxx;
    }
};
