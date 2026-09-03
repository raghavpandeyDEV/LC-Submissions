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
    vector<vector<vector<int>>>dp(n , vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
        
    }


};