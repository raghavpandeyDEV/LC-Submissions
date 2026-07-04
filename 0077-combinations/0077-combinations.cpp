class Solution {
public:
   void solve(int i , int cnt , int k , vector<int>&nums,vector<int>&temp , vector<vector<int>>&ans){
    if(cnt==k){
        ans.push_back(temp);
        return;
    }
    if(i>=nums.size())return;
    
    temp.push_back(nums[i]);
    solve(i+1,cnt+1,k,nums,temp,ans);
    temp.pop_back();
    solve(i+1,cnt,k,nums,temp,ans);

   }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>nums;
        vector<int>temp;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        solve(0,0,k,nums,temp,ans);
        return ans;
    }
};