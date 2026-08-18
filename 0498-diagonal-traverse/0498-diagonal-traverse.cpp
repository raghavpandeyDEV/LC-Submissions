class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        map<int,vector<int>>mpp; // { index_sum ,mat[i][j]}

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int indexSum=i+j;
                mpp[indexSum].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool ltr=false;
        for(auto it : mpp){
            if(ltr){
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
            }
            }
            else{
                for(int i=it.second.size()-1;i>=0;i--){
                ans.push_back(it.second[i]);
            }
            }
            ltr=!ltr;
        }
        return ans;

    }
};