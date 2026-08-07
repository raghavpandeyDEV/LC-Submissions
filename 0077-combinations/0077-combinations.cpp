class Solution {
public:
    void solve(int i , int k , vector<int>&arr,vector<int>&temp , vector<vector<int>>&ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        if(i==arr.size())return;

        temp.push_back(arr[i]);
        solve(i+1,k,arr,temp,ans);
        temp.pop_back();
        solve(i+1,k,arr,temp,ans);


    }
    vector<vector<int>> combine(int n, int k) {
       vector<int>arr;
       vector<int>temp;
       vector<vector<int>>ans;
       for(int i=1;i<=n;i++){
        arr.push_back(i);
       } 

       solve(0,k,arr,temp,ans);
       return ans;
    }
};