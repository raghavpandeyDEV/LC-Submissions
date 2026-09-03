class Solution {
public:
    int solve(int i,int amount ,vector<int>& coins ,vector<vector<int>>&dp ){
        if(i==0){
            return (amount%coins[0]==0);
        }
        if(dp[i][amount]!=-1)return dp[i][amount];

        int notPick=solve(i-1,amount,coins,dp);
        int pick=0;
        if(coins[i]<=amount){
            pick=solve(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);

        // TC : O(n*(amount+1))
        // SC: O(n*(amount+1)) + O(n)

        
    }

    
};