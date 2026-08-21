class Solution {
public:
    int solve(int i , vector<int>&nums ,vector<int>&dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int one=nums[i]+solve(i+1,nums,dp);
        int two=nums[i]+solve(i+2,nums,dp);

        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};
