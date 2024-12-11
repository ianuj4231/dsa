class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
                set<string> set(wordlist.begin(), wordlist.end());
                queue<pair<string, int>> q;
                if(beginword==endword){
                        return 1;
                }
                if(set.find(endword)==set.end())
                {
                    return 0;
                }
                 q.push({beginword, 1});
                while(! q.empty()){
                      string currentword=q.front().first;
                      int level=q.front().second;
                      q.pop();
                      for(int i=0;i<currentword.size();i++){
                           string tempword=currentword;
                           for(char ch='a';ch<='z';ch++){
                               tempword[i]=ch;
                                if(tempword==endword){
                                      return level+1;
                                }
                               if(set.find(tempword)!=set.end()){
                                   set.erase(tempword);
                                   q.push({tempword,level+1});
                               }
                           }
                      }
                }
                return 0;
    }
};
// time -  o m*n 
//space is o N 
