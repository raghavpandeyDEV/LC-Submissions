class Solution {
public:
    bool isPossible(string&s1 , string&s2){
        //s1->larger string

        if(s1.size()!=s2.size()+1)return false;
        int first=0;
        int second=0;

        while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size())return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        //sort length-wise : 

		sort(words.begin(), words.end(),
     [](string &a, string &b){
         return a.size() < b.size();
     });

		vector<int>dp(n, 1);
		int maxi = INT_MIN;
		int lastIndex = -1;
		
		for (int idx = 0; idx<n; idx++) {
			for (int prv = 0; prv<idx; prv++) {
				if (isPossible(words[idx] , words[prv]) && dp[prv] + 1 > dp[idx]) {
					dp[idx] = dp[prv] + 1;
				}
			}
			if (dp[idx]>maxi) {
				maxi = dp[idx];
				lastIndex = idx;
			}
		}
		
    return maxi;
    }
};