class TimeMap {

unordered_map<string, vector< pair<string , int > >> mp;
public:
    TimeMap() {
           
    }
    void set(string key, string value, int timestamp){
            mp[key].push_back({value, timestamp});
    }
  
    
    string get(string key, int timestamp) {
         if(mp.find(key)==mp.end()){
                    return "";
         }

         vector< pair<string , int >> nums=mp[key];
         int n=nums.size();
         int left=0, right=n-1;
                   string res = "";
         while(left<=right){
            int mid=left+(right-left)/2;
             if(nums[mid].second<=timestamp){
                        res=nums[mid].first;  // immediately capture the result, if it is <=  and move forward...coz u need the most recent valuel
                        left=mid+1;
             }
             else{
                right=mid-1;
             }
         }
         return res;
    }
};

// use example 2 4 6 8 10///.. and if  timestamp is 6 
