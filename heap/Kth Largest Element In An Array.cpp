class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int,vector<int>,greater<int>> minh;
            for(int x: nums){
                minh.push(x);
                if(minh.size()>k){
                    minh.pop();
                }
            }
            return minh.top();
    }
};  // top points to kth maximum... if 83 and 39 are ther... top will point to 39
