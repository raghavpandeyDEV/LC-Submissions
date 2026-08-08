class Solution {
public:
    int longestSubstring(string s, int k) {

        int maxi = 0;

        for (int i = 0; i < s.size(); i++) {

            unordered_map<char, int> mpp;

            for (int j = i; j < s.size(); j++) {

                mpp[s[j]]++;

                bool valid = true;

                for (auto it : mpp) {
                    if (it.second < k) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};