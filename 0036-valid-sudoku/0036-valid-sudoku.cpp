class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       //checking row-wise
       for(int i=0;i<9;i++){
        set<int>st;
        for(int j=0;j<9;j++){
          if(board[i][j]=='.')continue;
          if(st.find(board[i][j])!=st.end())return false;
          st.insert(board[i][j]);
        }
       } 

       //checking columns
       for(int j=0;j<9;j++){
        set<int>st;
        for(int i=0;i<9;i++){
          if(board[i][j]=='.')continue;
          if(st.find(board[i][j])!=st.end())return false;
          st.insert(board[i][j]);
        }
       } 
     
      //checking boxwise

      for(int i=0;i<9;i=i+3){
        for(int j=0;j<9;j=j+3){
            set<int>st;
            for(int row=i;row<i+3;row++){
                for(int col=j;col<j+3;col++){
                if(board[row][col]=='.')continue;
          if(st.find(board[row][col])!=st.end())return false;
          st.insert(board[row][col]);
                }
            }
        }
      }
  return true;
    }
};