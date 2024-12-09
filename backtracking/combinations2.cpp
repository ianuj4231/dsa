#include<bits/stdc++.h>
using namespace std;

void bt( vector<vector<int>>&  res, vector<int>& curr,vector<int>& nums, int index, int target){
                        if(target==0){
                          res.push_back(curr);
                          return ;
                        }
                        for(int i=index;i<nums.size();i++){
                            if(i> index && nums[i]==nums[i-1])continue;
                           if(nums[i]<=target){
                               curr.push_back(nums[i]);
                               bt(res, curr, nums, i+1, target-nums[i]);
                              curr.pop_back();
                           }
                        }
}
 
vector<vector<int>> combinations1(vector<int> &nums, int target ){
    vector<vector<int>> res;
    vector<int> curr;
    sort(nums.begin() , nums.end());
    bt(res , curr , nums, 0 , target);
    return res;
}

int main(){
     vector<int> nums={9,2,2,4,6,1,5 };
     int target = 8;
     vector<vector<int>> finalx = combinations1(nums, target);
     for(int i=0;i<finalx.size();i++){
       for(int x: finalx[i]){
         cout<<x<<" ";
       }
       cout<<endl;
     }
}
