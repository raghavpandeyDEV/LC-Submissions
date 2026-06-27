class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n=numCourses;
    vector<int>ans;
    vector<int>indegree(n,0);
    vector<vector<int>>adj(n);
    queue<int>q;

    for(int i=0;i<prerequisites.size();i++){
         int task=prerequisites[i][0];
         int pre=prerequisites[i][1];
         adj[pre].push_back(task);
         indegree[task]++;
    }

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }

    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;

            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(ans.size()==n)return true;
    return false;
        
    }
};