class Solution {
public:

    vector<int>lmax(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        ans[0]=arr[0];
        
        for(int i=1;i<n;i++){
            ans[i]=max(arr[i],ans[i-1]);
        }
        return ans;
    }
    
    vector<int>rmax(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        ans[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            ans[i]=max(arr[i],ans[i+1]);
        }
        return ans;
    }



    int trap(vector<int>& height) {
        // 0 , n-1 -> 0 
        //1 to n-2
        // evry index -> ( min( rmax , lmax) - arr[i])

        vector<int>rMax=rmax(height);
        vector<int>lMax=lmax(height);

        int sum=0;
        for(int i=1;i<height.size()-1;i++){
            sum+=(min(rMax[i],lMax[i])-height[i]);
        }
     return sum;
    }
};