class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>row[9];
         unordered_set<char>columns[9];
          unordered_set<char>boxs[9];

          for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char num=board[r][c];

                if(num=='.'){
                    continue;
                }

                int box=(r/3)*3+(c/3);

                if(row[r].count(num)||columns[c].count(num)||boxs[box].count(num)){
                    return false;
                }

                row[r].insert(num);
                columns[c].insert(num);
                boxs[box].insert(num);


            }
            
          }

          return true;

        
    }
};