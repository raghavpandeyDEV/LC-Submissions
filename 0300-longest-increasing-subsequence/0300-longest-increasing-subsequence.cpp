class Solution {
public:
    int solve(int i ,int prv , vector<int>& nums , vector<vector<int>>&dp ){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prv+1]!=-1)return dp[i][prv+1];
        int notPick=solve(i+1,prv,nums,dp);
        int pick=0;
        if(prv==-1 || nums[i]>nums[prv])pick=1+solve(i+1,i,nums,dp);

        return dp[i][prv+1]= max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
        for(int i=n-1;i>=0;i--){
            for(int prv=i-1;prv>=-1;prv--){
        int notPick=dp[i+1][prv+1];
        int pick=0;
        if(prv==-1 || nums[i]>nums[prv])pick=1+dp[i+1][i+1];

         dp[i][prv+1]= max(pick,notPick);
            }
        }

return dp[0][-1+1];
        //second state me har jgh + 1
    }
};