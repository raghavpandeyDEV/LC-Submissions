class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      
		int n = nums.size();
		sort(nums.begin(),nums.end());

		vector<int>dp(n, 1);
		vector<int>hash(n);
		
		for (int i = 0; i<n; i++) {
			hash[i] = i;
		}
		
		int maxi = INT_MIN;
		int lastIndex = -1;
		
		for (int idx = 0; idx<n; idx++) {
			for (int prv = 0; prv<idx; prv++) {
				if (nums[idx]%nums[prv]==0 && dp[prv] + 1 > dp[idx]) {
					dp[idx] = dp[prv] + 1;
					hash[idx] = prv;
				}
			}
			if (dp[idx]>maxi) {
				maxi = dp[idx];
				lastIndex = idx;
			}
		}
		vector<int>ans;
		ans.push_back(nums[lastIndex]);
		while (hash[lastIndex] != lastIndex) {
			lastIndex = hash[lastIndex];
			ans.push_back(nums[lastIndex]);
			
		}
		
		return ans;
		
	
    }
};