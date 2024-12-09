class Solution {
private:
priority_queue<int, vector<int>   , greater<int>   > minheap;
public:
    int findKthLargest(vector<int>& nums, int k) {
            for(int num: nums){
                  minheap.push(num);
                if(minheap.size() > k){
                      minheap.pop();
                }
            }
            return minheap.top();
        
    }
};
