class Solution {
public:
    bool solve(int i , int j , int k , string&s1, string&s2, string&s3,    vector<vector<vector<int>>>&dp){
          
      int n=s1.size();
        int m=s2.size();
        int N=m+n;

        if(i==n && j==m && k==N)return true;
        if(k>=N)return false;//other string doesnt get consumed at all
         if(dp[i][j][k]!=-1)return dp[i][j][k];
        bool result1=false;
        bool result2=false;

        if(s1[i]==s3[k]){
           result1= solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(s2[j]==s3[k]){
        result2=solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j][k]= result1 || result2;
      
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int N=m+n;

        if(s3.size()!=N)return false;
    vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(m + 1, vector<int>(N + 1, -1)));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};