class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        vector<int > res(n);
        stack<pair<int , int>> st;
        for(int i=0;i<nums.size();i++){
              while(!st.empty() && st.top().first < nums[i]){
                  res[ st.top().second ] =  i - st.top().second ;
                  st.pop();
              }
              st.push({ nums[i] ,  i });
        } 
   return res;
    }
};
