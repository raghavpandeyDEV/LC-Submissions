class Solution {
public:
    void solve(int i ,int target , vector<int>&temp , vector<vector<int>>&ans , int k){
        if(target==0 && temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        if(i>9 || temp.size()==k)return;

        temp.push_back(i);
        solve(i+1,target-i,temp,ans,k);
        temp.pop_back();
        solve(i+1,target,temp,ans,k);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>>ans;
         vector<int>temp;
         solve(1,n,temp,ans,k);

         return ans;

        

    }
};