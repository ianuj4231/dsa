class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
          int m=nums.size();
          int n=nums[0].size();
          int left=0, right=m*n-1;
          while(left<=right){
             int mid=left+(right-left)/2;
             int midele=nums[mid/n][mid%n];
             if(midele==target){
                    return true;
             }
             else if(midele>target){
                    right=mid-1;
             }
             else{
                    left=mid+1;
             }
          }            
        return false;
    }
};
