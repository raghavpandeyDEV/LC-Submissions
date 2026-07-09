class Solution {
public:
    int solve(int i , int target , vector<int>&coins ){
        if(i==0){
           if(target%coins[i]==0)return target/coins[i] ;
           return 1e9;
        }
      int notPick=solve(i-1,target,coins);
      int pick=1e9;
      if(target>=coins[i]){
        pick=1+solve(i,target-coins[i],coins);
      }

      return min(pick,notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1));
      
        for(int target=0;target<=amount;target++){ //all possible values of target for 0-index
            if(target%coins[0]==0)dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;
        }

            for(int i=1;i<n;i++){
                for(int target=0;target<=amount;target++){
                    int notPick=dp[i-1][target];
                    int pick=1e9;
                    if(target>=coins[i])pick=1+dp[i][target-coins[i]];
                    dp[i][target]=min(pick , notPick);
                }
            }
        
     if(dp[n-1][amount]==1e9)return -1;
     return dp[n-1][amount];
    }
};