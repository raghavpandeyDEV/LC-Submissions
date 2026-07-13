class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i==0 && j==0 )return arr[0][0];
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];

        int up=arr[i][j]+solve(i-1,j,arr,dp);
        int left=arr[i][j]+solve(i,j-1,arr,dp);

        return dp[i][j]= min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));
        
        dp[0][0]=grid[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                else{
                    int up=1e9;
                    int left=1e9;
        if(i>0) up=grid[i][j]+dp[i-1][j];
        if(j>0) left=grid[i][j]+dp[i][j-1];

        dp[i][j]= min(up,left);  
                }
            }
        }
        return dp[m-1][n-1];
    }
};