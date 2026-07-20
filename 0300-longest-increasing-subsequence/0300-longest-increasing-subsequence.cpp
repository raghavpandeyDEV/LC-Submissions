class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      // special code 
      int n=nums.size();

      vector<int>dp(n,1);

      for(int idx=0;idx<n;idx++){
        for(int prv=0;prv<idx;prv++){
            if(nums[prv]<nums[idx]){
                dp[idx]=max(dp[idx],1+dp[prv]);
            }
        }
      }
      int maxi=INT_MIN;
      
      for(int i=0;i<n;i++){
        maxi=max(maxi,dp[i]);
      }
      return maxi;
    }
};