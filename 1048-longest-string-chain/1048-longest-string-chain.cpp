class Solution {
public:
    bool isPossible(string&s1 , string&s2){
        //s1->larger string
        if(s1.size()!=s2.size()+1)return false;
        

        int i=0;
        int j=0;
        while(i<s1.size()){
            if(j<s2.size() && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size())return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        //sort length-wise : 

		sort(words.begin(), words.end(),
     [](string &a, string &b){
         return a.size() < b.size();
     });

     vector<int>dp(n,1); 

     int maxi=0;

     for(int i=0;i<n;i++){
        for(int prv=0;prv<i;prv++){
            if(isPossible(words[i],words[prv])){
                dp[i]=max(dp[i],dp[prv]+1);
            }
        }
        maxi=max(maxi,dp[i]);
     }
  return maxi;
    }
};