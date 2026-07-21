class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> freq;
        int n=grid.size();

        for (auto& row : grid)
            freq[row]++;

        int cnt = 0;

        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++)
                col.push_back(grid[i][j]);

            cnt += freq[col];
        }
        return cnt;
    }
};