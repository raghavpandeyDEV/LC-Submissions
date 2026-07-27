class Solution {
public:
  void dfs(int node ,vector<int>&temp, vector<int>&vis , vector<vector<int>>&graph , vector<vector<int>>&ans){
     int n=graph.size();
     if(node==n-1){
        temp.push_back(node);
        ans.push_back(temp);
        return ;
    }
   temp.push_back(node);
    vis[node]=1;
    

    for(auto it : graph[node]){
        if(vis[it]==-1)
        {
            dfs(it,temp,vis,graph,ans);
            temp.pop_back();
            vis[it]=-1;
    }
    }
  }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(n,-1);
        dfs(0,temp ,vis,graph,ans);
        return ans;

      
    }
};