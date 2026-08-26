class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
          int sr=startPos[0];
        int sc=startPos[1];

        int er=homePos[0];
        int ec=homePos[1];
       
        if(sr==er && sc==ec)return 0;
        int sum=0;

        if(sr<er){
          for(int i=sr+1;i<=er;i++){
         sum+=rowCosts[i];
          }
        }
        else{
            for(int i=sr-1;i>=er;i--){
                sum+=rowCosts[i];
            }
        }

        if(sc<ec){
            for(int i=sc+1;i<=ec;i++){
         sum+=colCosts[i];
          } 

        }
        else{
            for(int i=sc-1;i>=ec;i--){
            sum+=colCosts[i];
            }
        }
        return sum;
    }
};