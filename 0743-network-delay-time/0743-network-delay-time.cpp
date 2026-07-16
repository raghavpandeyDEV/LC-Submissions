class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //{dis,node}
        pq.push({0,k});
        dis[k]=0;
        
        //making adj list
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];

            adj[u].push_back({v,wt});
        }

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
              int adjNode=it.first;
              int wt=it.second;

              if(dis[adjNode]>wt+d){
                pq.push({wt+d,adjNode});
                dis[adjNode]=wt+d;
              }
            }
        }
      int maxi=INT_MIN;
      for(int i=1;i<=n;i++){
        if(dis[i]==1e9)return -1;
        maxi=max(maxi,dis[i]);
      }

      return maxi;
    }
};