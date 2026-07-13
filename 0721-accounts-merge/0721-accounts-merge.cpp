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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
     int n=accounts.size();
     DisjointSet ds(n);

     unordered_map<string,int>mpp;
     for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string email=accounts[i][j];
         if(mpp.find(email)==mpp.end())mpp[email]=i;
         else ds.unionBySize(i,mpp[email]);
        }
     }
        vector<vector<string>>mergedMails(n);

        for(auto it : mpp){
            string email=it.first;
            int node=ds.findUPar(it.second);
            mergedMails[node].push_back(email);
        }
        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(mergedMails[i].size()==0)continue;
            vector<string>temp;
            string name=accounts[i][0];
            temp.push_back(name);
            sort(mergedMails[i].begin(),mergedMails[i].end());
            
            for(auto it : mergedMails[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }
     
     return ans;
    }
};