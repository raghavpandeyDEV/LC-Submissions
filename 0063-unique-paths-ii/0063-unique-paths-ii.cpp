class Solution {
public:
   int solve(int i ,int j ,vector<vector<int>>&arr , vector<vector<int>>&dp){ 
    if(i==0 && j==0 ){
        if(arr[i][j]==1)return 0;
        else return 1;
    }
    
    if(i<0 || j<0 || arr[i][j]==1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    

    int up=solve(i-1,j,arr,dp);
    int left=solve(i,j-1,arr,dp);
    
    return dp[i][j] =up+left;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));

        if(obstacleGrid[0][0]==1)dp[0][0]=0;
        else dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
            else{  
                if(obstacleGrid[i][j]==1)
                {dp[i][j]=0;
                continue;
                }
              int up=0;
              int left=0;

            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];
    
         dp[i][j]=up+left;
            }
        }
        }

      return dp[m-1][n-1];   
        
    }
};