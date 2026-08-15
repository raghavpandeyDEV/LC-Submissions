class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // prefix[i] = sum of first i elements
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> ans;

        for(int x : queries) {

            // first element >= x
            int pos = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

            // Left side: x - nums[i]
            long long leftSum = 1LL * x * pos - prefix[pos];

            // Right side: nums[i] - x
            long long rightSum = (prefix[n] - prefix[pos])
                               - 1LL * x * (n - pos);

            ans.push_back(leftSum + rightSum);
        }

        return ans;
    }
};