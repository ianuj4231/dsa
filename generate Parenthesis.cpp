class Solution {
public:
    vector<string> generateParenthesis(int n) {
               vector<string>res;
                function<void(int , int, string )> bt=[&](int open, int close, string curr){
                      if(2*n==curr.size())
                            {   
                                res.push_back(curr);
                                return ;
                            }
                      if(open< n){
                        bt(open+1, close,curr+"(" );
                      }
                      if(close< open){
                          bt(open, close+1,curr+")" );
                      }
                };
                bt(0,0,"");
                return res;
    }
};
