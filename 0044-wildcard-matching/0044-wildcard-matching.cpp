class Solution {
public:
    bool solve(int i , int j , string&s, string&p ,vector<vector<int>>&dp){
      if(i==0 && j==0)return true;
      if(i==0){
        for(int idx=0;idx<j;idx++)if(p[idx]!='*')return false;
        return true;
      }
      if(j==0)return false;
      if(dp[i][j]!=-1)return dp[i][j];

      if(p[j-1]==s[i-1] || p[j-1]=='?')return dp[i][j]=solve(i-1,j-1,s,p,dp);
       if(p[j-1]=='*') return dp[i][j]= solve(i, j-1 ,s,p,dp) || solve(i-1,j,s,p,dp);
       return false;
      
    }
    bool isMatch(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(n1,n2,s,p,dp);

        //TC : O(n1*n2)
        //sc : o(n1*n2) + O(n1+n2)   
    
        }
};