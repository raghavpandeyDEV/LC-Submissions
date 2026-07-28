class Solution {
public:
     int solve(vector<int>& nums) { 

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


   int rob(vector<int>& nums) {

    int n = nums.size();

    if (n == 1)
        return nums[0];

    vector<int> t1, t2;

    for (int i = 0; i < n; i++) {
        if (i != 0)
            t1.push_back(nums[i]);

        if (i != n - 1)
            t2.push_back(nums[i]);
    }

    return max(solve(t1), solve(t2));
}
};