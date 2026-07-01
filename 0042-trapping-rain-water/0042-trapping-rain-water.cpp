class Solution {
public:
   void leftMax(vector<int>arr,vector<int>&ans){
    ans[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        ans[i]=max(arr[i],ans[i-1]);
    }
   }

   void rightMax(vector<int>arr,vector<int>&ans){
    ans[arr.size()-1]=arr[arr.size()-1];
    for(int i=arr.size()-2;i>=0;i--){
        ans[i]=max(arr[i],ans[i+1]);
    }
   }
    int trap(vector<int>& height) {
        vector<int>left(height.size());
        vector<int>right(height.size());

        int ans=0;
        leftMax(height, left);
rightMax(height, right);

        for(int i=0;i<height.size();i++){
            if(height[i]>=left[i] || height[i]>=right[i])continue;
            ans+=(min(left[i],right[i])-height[i]);
        }

        return ans;

    }
};