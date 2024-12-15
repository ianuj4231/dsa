class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
                int  m  = board.size();
                int n = board[0].size();
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                          if(bt(board, word, i, j, 0)){
                              return true;
                          }
                    }
                }
                return false;
    }

    bool bt(vector<vector<char>>& board, string word, int i, int  j,  int index){
                if(index==word.size()){
                    return true;
                }
                if(i<0||j<0||i>=board.size()||j>=board[0].size()||word[index]!=board[i][j]){
                    return false;
                }
                char temp=board[i][j];
                board[i][j]='#';
                
                bool found=  bt(board, word, i, j-1, index+1) ||
                             bt(board, word, i-1, j, index+1) ||
                             bt(board, word, i+1, j, index+1) ||
                             bt(board, word, i, j+1, index+1) ;
                
                board[i][j] = temp;
                return found;
    }   

};
