class Solution {
public:   
    bool isValid(int i , int cnt , string &s , vector<vector<int>>&dp){
        if(cnt<0)return false;
        if(i==s.size()){
            if(cnt==0)return true;
            return false;
        }
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        if(s[i]=='(')return isValid(i+1,cnt+1,s,dp);
       else if(s[i]==')')return isValid(i+1,cnt-1,s,dp);
       return dp[i][cnt]=(isValid(i+1,cnt+1,s,dp) || isValid(i+1,cnt-1,s,dp) || isValid(i+1,cnt,s,dp));
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return isValid(0,0,s,dp);
        
    }
};