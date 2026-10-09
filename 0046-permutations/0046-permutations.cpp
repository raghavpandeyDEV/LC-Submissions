class Solution {
public:
    void solve(int idx , vector<int>&vis ,vector<int>& nums, vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==-1){
                temp.push_back(nums[i]);
                vis[i]=1;
                solve(idx+1,vis,nums,temp,ans);
                temp.pop_back();
                vis[i]=-1;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n,-1);
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,vis,nums,temp,ans);
        return ans;
        
    }
};