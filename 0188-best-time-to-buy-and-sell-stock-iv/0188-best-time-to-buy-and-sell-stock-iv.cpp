class Solution {
public:
   int solve(int i , int buy , vector<int>& arr,int cap,int k){
     if(cap==0)return 0;
     if(i==arr.size())return 0;
     

     int profit=0;
     if(buy){
        profit=max(-arr[i]+solve(i+1,0,arr,cap,k),solve(i+1,1,arr,cap,k));
     }
     else{
        profit=max(arr[i]+solve(i+1,1,arr,cap-1,k),solve(i+1,0,arr,cap,k));
     }
     return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
      int n=prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        
        //cap==0 
        for(int i=0;i<=n;i++){
        for(int buy=0;buy<=1;buy++){
            dp[i][buy][0]=0;
        }
        }

        // ind==n
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=k;cap++){
                dp[n][buy][cap]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=k;cap>=1;cap--){
                   int profit=0;
     if(buy){
        profit=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
     }
     else{
        profit=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
     }
     dp[i][buy][cap]=profit; 
                }
            }
        }
      return dp[0][1][k];
    }
};