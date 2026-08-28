class Solution {
public:
    int solve(int i , int buy ,vector<int>&nums,int cnt , vector<vector<vector<int>>>& dp){
        if(cnt==0)return 0;
        if(i==nums.size())return 0;
        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];

        int profit=0;
        if(buy){
            profit=max(-nums[i]+solve(i+1,0,nums,cnt,dp) , solve(i+1,1,nums,cnt,dp));
        }
        else{
            profit=max(nums[i]+solve(i+1,1,nums,cnt-1,dp) , solve(i+1,0,nums,cnt,dp));
        }
        return dp[i][buy][cnt]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();

       vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(k+1,0))
        );
       
       
       //cnt==0;
       for(int i=0;i<n;i++){
        for(int buy=0;buy<=1;buy++){
            dp[i][buy][0]=0;
        }
       }

       // i==n
       for(int buy=0;buy<=1;buy++){
        for(int cnt=0;cnt<=k;cnt++){
            dp[n][buy][cnt]=0;
        }
       }

       for(int i=n-1;i>=0;i--){
        for(int buy=1;buy>=0;buy--){
            for(int cnt=k;cnt>0;cnt--){
            
             int profit=0;

        if(buy){
            profit=max(-prices[i]+dp[i+1][0][cnt] , dp[i+1][1][cnt]);
        }
        else{
            profit=max(prices[i]+dp[i+1][1][cnt-1], dp[i+1][0][cnt]);
        }
         dp[i][buy][cnt]=profit;

            }
        }
       }
        return dp[0][1][k];
    }
};