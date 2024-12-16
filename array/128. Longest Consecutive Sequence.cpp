class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int maxx=INT_MIN;
        if(nums.empty())return 0;
        map<int, bool >mp;
        for(int x: nums){
            mp[x]=false;
        }
        int maxx=INT_MIN;
        for(int x: nums){
             int currlen=1;
             int pn=x-1;
             while(mp.find(pn)!=mp.end() && mp[pn]==false ){
                        mp[pn]=true;
                        currlen++;
                        pn--;
             }

            int nn=x+1;
             while(mp.find(nn)!=mp.end() && mp[nn]==false ){
                        mp[nn]=true;
                        currlen++;
                        nn++;
             }
             maxx=max(maxx, currlen);
        }
        return maxx;
    }
};
