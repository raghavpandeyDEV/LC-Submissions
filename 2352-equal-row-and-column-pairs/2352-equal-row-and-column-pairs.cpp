class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,vector<int>>rows;
        map<vector<int>,vector<int>>columns;

        for(int i=0;i<n;i++){
            vector<int>row;
            for(int j=0;j<n;j++){
               row.push_back(grid[i][j]);
            }
            rows[row].push_back(i);
        }

        for(int j=0;j<n;j++){
            vector<int>column;
            for(int i=0;i<n;i++){
               column.push_back(grid[i][j]);
            }
            columns[column].push_back(j);
        }
         
        int cnt=0;

       for(auto it : rows){
        if(columns.find(it.first)!=columns.end()){
            cnt += it.second.size() * columns[it.first].size();
        }
       }
     return cnt;

    }
};