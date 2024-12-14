class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()==1)return 0;
        int n=nums.size();
        int maxxc=0, lastjumpidx=0,jumps=0;
        for(int i=0;i<n;i++){
            maxxc=max(maxxc, i+nums[i]);
            if(i==lastjumpidx){
                 jumps++;
                 lastjumpidx=maxxc;
                 if( maxxc >=n-1 ){
                    return jumps;
                 }
            }
        }
        return jumps;
    }
};
