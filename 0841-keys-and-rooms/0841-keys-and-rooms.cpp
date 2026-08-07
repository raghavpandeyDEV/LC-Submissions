class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n =rooms.size();
        vector<int>vis(n,-1);

        queue<int>q;
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it : rooms[node]){
                if(vis[it]==-1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }

        for(int i=0;i<vis.size();i++){
            if(vis[i]!=1)return false;
        }
        return true;
    }
};