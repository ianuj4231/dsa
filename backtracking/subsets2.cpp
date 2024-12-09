#include<bits/stdc++.h>
using namespace std;

void bt( vector<vector<int>>&  res, vector<int>& curr,vector<int>& nums, int index){
                        res.push_back(curr);
                        for(int i=index;i<nums.size();i++){
                            if(i> index && nums[i]==nums[i-1])continue;
                            curr.push_back(nums[i]);
                            bt(res, curr, nums,i+1  );
                            curr.pop_back();
                        }
}

vector<vector<int>> subsets2(vector<int> &nums){
    vector<vector<int>> res;
    vector<int> curr;
    sort(nums.begin() , nums.end());
    bt(res , curr , nums, 0 );
    return res;
}

int main(){
     vector<int> nums={1, 2, 1};
     vector<vector<int>> finalx = subsets2(nums);
     for(int i=0;i<finalx.size();i++){
       for(int x: finalx[i]){
         cout<<x<<" ";
       }
       cout<<endl;
     }
}
