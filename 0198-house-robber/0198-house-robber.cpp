class Solution {
public:
    int solve(int i , vector<int>& nums,vector<int>&dp ){
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        
         int pick=0;
         pick=nums[i]+solve(i-2,nums,dp);
         int notPick=solve(i-1,nums,dp);

         return dp[i]=max(pick,notPick);

    }
    int rob(vector<int>& nums) { 

        int n=nums.size();

         if (n == 1)   return nums[0];

        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){

         int pick=nums[i];
         if(i>1)pick=nums[i]+dp[i-2];
         int notPick=dp[i-1];

        dp[i]=max(pick,notPick);

        }
        return dp[n-1];
       
    }
};