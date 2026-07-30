class DisjointSet {
 public : 
  vector<int>parent,rank,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
             parent[i]=i;
        }
    }

    int findUPar(int node){
        if(parent[node]==node)return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v]){
           parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u , int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v)return;
        if(size[ulp_u] < size[ulp_v]){
           parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n+1);

        for(auto it : edges){
           int u=it[0];
           int v=it[1];
           if(ds.findUPar(u)!=ds.findUPar(v)){
            ds.unionBySize(u,v);
           }
           else{
            return {u,v};
           }
        }
    return {-1,-1};
    }
};