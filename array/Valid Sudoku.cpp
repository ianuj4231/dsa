class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
                vector<unordered_set<char>> rows(9), cols(9), subgrid(9);
         for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                       char num=board[i][j];
                        if(num=='.')continue;
                        if(subgrid[(i / 3) * 3 + (j / 3)].count(num)  // 9 subgrud.. means subgrid[8] 8,8 ...8/3= 2 => 2* 3 + 8/3= 8.. so i/3 * 3 + j /3 
                                ||cols[j].count(num)
                                ||rows[i].count(num)
                        ){
                            return false;
                        }
                        subgrid[(i / 3) * 3 + (j / 3)].insert(num);
                        rows[i].insert(num);
                        cols[j].insert(num);
                }
         }
         return true;
    }
};

/*
Time Complexity:
O(1), because the board size is fixed at 9x9, so we always process exactly 81 cells.
Space Complexity:
O(1), because the space used for the sets is also constant, as we're always dealing with 9 rows, 9 columns, and 9 subgrids.
*/
