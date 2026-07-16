class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
      
      // forming adj list 
      vector<vector<pair<int,int>>>adj(n);

      for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
      } 
vector<vector<int>>dis(n,vector<int>(n,1e9)); //dist of each node from every other node
for(int src=0; src<n; src++){

            priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>> pq;

            dis[src][src]=0;
            pq.push({0,src});

            while(!pq.empty()){

                auto [d,node]=pq.top();
                pq.pop();

                if(d>dis[src][node]) continue;

                for(auto &[adjNode,wt]:adj[node]){

                    if(dis[src][adjNode]>d+wt){
                        dis[src][adjNode]=d+wt;
                        pq.push({dis[src][adjNode],adjNode});
                    }
                }
            }
        }

         int ans=-1;
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=distanceThreshold)
                    cnt++;
            }

            if(cnt<=mini){
                mini=cnt;
                ans=i;
            }
        }

        return ans;
    

    }
};