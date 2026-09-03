class Solution {
public:
    int solve(int i , int buy , int cnt ,vector<int>&arr,vector<vector<vector<int>>>&dp){
        if(i==arr.size() || cnt==0 )return 0;

        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];

        int profit=0;
        if(buy){
        profit = max(-arr[i]+solve(i+1,0,cnt,arr,dp) , solve(i+1,1,cnt,arr,dp));
        }
        else{
        profit=max(arr[i]+solve(i+1,1,cnt-1,arr,dp) , solve(i+1,0,cnt,arr,dp));
        }
        return dp[i][buy][cnt] =profit;
    }
    int maxProfit(int k, vector<int>& prices) {
     
        int n=prices.size();
    vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2, vector<int>(k+1,0)));
        // i==n
        for(int buy=0;buy<2;buy++){
            for(int cnt = k ;cnt>=0;cnt--){
                dp[n][buy][cnt]=0;
                            }
        }

        // cnt==0;
        for(int i=0;i<n;i++){
            for(int buy=0;buy<2;buy++){
                dp[i][buy][0]=0;
            }
        }

        

        for(int i=n-1;i>=0;i--){
         for(int buy=0;buy<2;buy++){
            for(int cnt=1;cnt<=k;cnt++){
                int profit=0;

        if(buy){
        profit = max(-prices[i]+dp[i+1][0][cnt] , dp[i+1][1][cnt]);
        }
        else{
        profit=max(prices[i]+dp[i+1][1][cnt-1] , dp[i+1][0][cnt]);
        }
        
        dp[i][buy][cnt] =profit;
            }
         }
        }

return dp[0][1][k] ;

  

        // tc : O(n*k+1) // sc : O(n*k+1) + O(n)
        
    }


};