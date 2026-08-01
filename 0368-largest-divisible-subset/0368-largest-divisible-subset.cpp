class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);

        sort(nums.begin(),nums.end());
        
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }

        int maxi=0;
        int lastIndex=-1;

        for(int i=0;i<n;i++){
            for(int prv=0;prv<i;prv++){
                if(nums[i]%nums[prv]==0 && dp[prv] + 1 > dp[i]){
                    dp[i]=dp[prv]+1;
                    hash[i]=prv;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
       
       vector<int>ans;
       ans.push_back(nums[lastIndex]);
       while(lastIndex!=hash[lastIndex]){
           lastIndex=hash[lastIndex];
           ans.push_back(nums[lastIndex]);
       }
       reverse(ans.begin(),ans.end());
      return ans;
    }
};