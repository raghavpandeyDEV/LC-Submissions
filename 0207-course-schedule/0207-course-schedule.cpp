class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // there should be no cylicity 
        // Kahn's algo -> DAG 
        int n=numCourses;

        vector<int>ans; // topo sort
        vector<int>indegree(n);
        vector<vector<int>>adj(n);

        for(auto it : prerequisites){
            //u->v
         int u=it[0];
         int v=it[1]; 
         adj[u].push_back(v);
        }

        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
         
         queue<int>q;

        for(int i=0;i<n;i++){
          if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(ans.size()==n)return true;
        return false;
        

    }
};