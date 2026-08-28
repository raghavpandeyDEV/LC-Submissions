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
            n, vector<vector<int>>(2, vector<int>(k+1, -1))
        );

        return solve(0,1,prices,k,dp);

        //tc: O ( n )
        //sc:o(n)+O(n)
    }
};