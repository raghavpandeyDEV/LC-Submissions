class Solution {
public:
    bool solve(int i , int j , string&s1, string&s2, string&s3,vector<vector<int>>&dp){
          
        int n=s1.size();
        int m=s2.size();
        int N=m+n;

        if(i==n && j==m && i+j==N)return true;
        
        if(dp[i][j]!=-1)return dp[i][j];
        bool result1=false;
        bool result2=false;

        if(s1[i]==s3[i+j]){
           result1= solve(i+1,j,s1,s2,s3,dp);
        }
        if(s2[j]==s3[i+j]){
        result2=solve(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j]= result1 || result2;
      
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int N=m+n;

        if(s3.size()!=N)return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};