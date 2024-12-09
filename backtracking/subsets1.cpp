#include<bits/stdc++.h>
using namespace std;

void bt( vector<vector<int>>&  res, vector<int>& curr,vector<int>& nums, int index){
                        res.push_back(curr);
                        for(int i=index;i<nums.size();i++){
                            curr.push_back(nums[i]);
                            bt(res, curr, nums,i+1  );
                            curr.pop_back();
                        }
}

vector<vector<int>> subsets1(vector<int> &nums){
    vector<vector<int>> res;
    vector<int> curr;
    bt(res , curr , nums, 0 );
    return res;
}

int main(){
     vector<int> nums={1, 2, 3};
     vector<vector<int>> finalx = subsets1(nums);
     for(int i=0;i<finalx.size();i++){
       for(int x: finalx[i]){
         cout<<x<<" ";
       }
       cout<<endl;
     }
}
