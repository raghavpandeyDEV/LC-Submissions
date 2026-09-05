class Solution {
public:
   int solve(int i , int buy , int cnt , vector<int>& prices ,vector<vector<vector<int>>>&dp){
    if(i==prices.size())return 0;
    if(cnt==0)return 0;
    if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];

    int profit=0;
    if(buy){
        profit=max(-prices[i]+solve(i+1,0,cnt,prices,dp) , solve(i+1,1,cnt,prices,dp));
    }
    else{
        profit=max(prices[i]+solve(i+1,1,cnt-1,prices,dp), solve(i+1,0,cnt,prices,dp));
    }
    return dp[i][buy][cnt]= profit;
   }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // 3d matrix -> n * 2 * cnt+1

        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);

        // TC : O(2^n)
        //SC : O(n)
    }
};