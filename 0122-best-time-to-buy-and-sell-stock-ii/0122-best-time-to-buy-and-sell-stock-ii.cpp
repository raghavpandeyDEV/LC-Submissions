class Solution {
public:
    int solve(int i , int buy , vector<int>& arr){
     if(i==arr.size())return 0;

     int profit=0;
     if(buy){
        profit=max(-arr[i]+solve(i+1,0,arr),solve(i+1,1,arr));
     }
     else{
        profit=max(arr[i]+solve(i+1,1,arr),solve(i+1,0,arr));
     }
     return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        dp[n][0]=0;
        dp[n][1]=0;


        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
              int profit=0;
      if(buy){
        profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
     }
      else{
        profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
     }
       dp[i][buy]= profit;   
            }
        }

        return dp[0][1];
    }
};