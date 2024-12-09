class Solution {
public:

    void bt(vector<bool> &used, vector<int>& nums, vector<vector<int>>& res, vector<int> &curr){
        if(curr.size()==nums.size()){
              res.push_back(curr);
              return;
        }
        for(int i=0;i<nums.size();i++){
               if(!used[i]){
               curr.push_back(nums[i]);
               used[i]=true;
               bt(used, nums, res, curr);
               used[i]=false;
               curr.pop_back();
               }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int > curr;
        vector<vector<int> > res;
        bt(used, nums, res, curr);
        return res; 
    }
};
