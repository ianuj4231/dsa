class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> res;
         vector<string> board(n, string(n,'.'));
         unordered_set<int> cols, diag1, diag2;
         bt(res, board, 0, n, cols, diag1, diag2);
         return res;
    }
    void bt(vector<vector<string>>& res, vector<string>& board, int row, int n,
                   unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2)
    {
           
           if(row==n){
            res.push_back(board);
            return;
           }
           
           for(int col=0;col<n;col++){
            if(cols.count(col)||diag1.count(row-col)||diag2.count(row+col)){
                 continue;
            }
           
            board[row][col]='Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);        
            
            bt(res, board, row + 1, n, cols, diag1, diag2);

            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};
