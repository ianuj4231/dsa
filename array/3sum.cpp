class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
              if(i>0 && nums[i]==nums[i-1])continue;
              int k=n-1;
              int j=i+1;
              while(j< k ){
                  int sum=nums[j]+nums[k]+nums[i];
                  if(sum==0){
                        res.push_back({  nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                        while(j< k && nums[j]==nums[j-1]  ){
                                j++;
                        }
                        while(j< k  &&  nums[k]==nums[k+1]){
                                k--;
                        }
                  }
                  else if(sum < 0 ){
                        j++;
                  }
                  else{
                     k--;
                  }
              }
        }
        return res;
    
}};
