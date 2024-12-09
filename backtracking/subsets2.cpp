class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int> >res;
            vector<int> current;
            bt(res, current, 0, nums);
            return res;
    }
    void bt(vector<vector<int>>& res, vector<int>& current, int index, vector<int>& nums) {
        res.push_back(current);
        for(int i=index;i<nums.size();i++){
                if(i> index && nums[i]==nums[i-1]){
                    continue;
                }
                current.push_back( nums[i] );
                bt(res, current, i+1, nums);
                current.pop_back();
        }
    }
};
