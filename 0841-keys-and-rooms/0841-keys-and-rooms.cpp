class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int n=rooms.size();
        vector<int>vis(n,-1);
          vis[0]=1;
        q.push(0);

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
        for(auto it : vis){
            if(it==-1)return false;
        }
        return true;
    }
};