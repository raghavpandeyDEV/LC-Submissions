class Solution {
public:
    int isSimilar(string&s1 , string&s2){
        int n=s1.size();
        int diff=0;
        for(int i=0;i<n;i++){
         if(s1[i]!=s2[i])diff++;
        }
        return (diff==0 || diff==2);
    }

    void dfs(int node , vector<int>&vis ,vector<vector<int>>&adj){
     vis[node]=1;

     for(auto it : adj[node]){
        if(vis[it]==-1)dfs(it,vis,adj);
     }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();

        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>vis(n,-1);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(i,vis,adj);
                cnt++;
            }
        }
  return cnt;
    }
};