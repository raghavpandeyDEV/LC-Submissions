class Solution {
public:
    vector<int>leftMax(vector<int>&arr){ // max height to the left of the index
       vector<int>ans(arr.size());
       ans[0]=0;
       for(int i=1;i<arr.size();i++){
        ans[i]=max(ans[i-1] , arr[i-1]);
       }
       return ans;
    }

     vector<int>rightMax(vector<int>&arr){ // max height to the right of the index
       int n=arr.size();
       vector<int>ans(arr.size());
       ans[n-1]=0;
       for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i+1] , arr[i+1]);
       }
       return ans;
    }
    
    int trap(vector<int>& height) {
        int n=height.size();
        int sum=0;
        vector<int>ans(n);

        vector<int>left=leftMax(height);
        vector<int>right=rightMax(height);

        for(int i=0;i<n;i++){
            if(height[i]>=left[i] || height[i]>=right[i])continue;
            sum+=(min(left[i],right[i])-height[i]);
        }
        return sum;
    }
};