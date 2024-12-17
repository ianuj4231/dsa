class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       set<char> set;
       if(s.empty() )return 0;
int ct=0, maxx=INT_MIN;
int start=0, end=0; 
 while(start< s.size())
 {

 if (set.find(s[start])==set.end()) 
{
	ct++;
set.insert(s[start]);
maxx=max(maxx, ct);
start++;
}
else{
set.erase(s[end]);
ct--;
maxx=max(maxx, ct);
end++;
}

    }
    return maxx;


    }
};
