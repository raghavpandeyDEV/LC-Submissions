class Solution {
public:
   int lowerBound(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        
        int ans=n;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }    
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back())temp.push_back(nums[i]);
            else{
                int index=lowerBound(temp,nums[i]);
                temp[index]=nums[i];
            }
        }

        return temp.size();
    }
};