class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(m + 1), right(m + 1);

        for (int mask = 0; mask < (1 << m); mask++) {
            int cnt = 0, sumL = 0, sumR = 0;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sumL += nums[i];
                    sumR += nums[i + m];
                }
            }
            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int i = 0; i <= m; i++)
            sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;

        for (int k = 0; k <= m; k++) {
            for (int s1 : left[k]) {
                auto &vec = right[m - k];
                int target = total / 2 - s1;

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }

                if (it != vec.begin()) {
                    --it;
                    int sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};