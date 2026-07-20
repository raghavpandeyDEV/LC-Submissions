class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       
      int n=nums.size();

      vector<int>dp(n,1);
    int maxi=INT_MIN;

      for(int idx=0;idx<n;idx++){
        for(int prv=0;prv<idx;prv++){
            if(nums[prv]<nums[idx]){
                dp[idx]=max(dp[idx],1+dp[prv]);
                
            }
        }
        maxi=max(maxi,dp[idx]);
      }
      
      return maxi;
    }
};