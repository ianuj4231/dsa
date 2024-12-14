class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxx=INT_MIN;
        for(int num: nums){
            currsum=max(currsum+num, num);
             maxx=max(maxx, currsum);
             if(currsum < 0 ){
                  currsum=0;
             }
        }
        return maxx;
    }
};
