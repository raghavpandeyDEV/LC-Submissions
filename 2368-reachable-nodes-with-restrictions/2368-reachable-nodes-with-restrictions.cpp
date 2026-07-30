class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<vector<int>> adj(n);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        unordered_set<int> st(restricted.begin(), restricted.end());

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans++;

            for (auto it : adj[node]) {
                if (!vis[it] && !st.count(it)) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return ans;
    }
};