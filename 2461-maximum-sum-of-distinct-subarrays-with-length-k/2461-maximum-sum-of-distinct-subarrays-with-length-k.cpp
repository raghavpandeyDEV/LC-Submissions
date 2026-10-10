class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int l=0;
        int r=k-1;
        int n=nums.size();

        long long sum=0;
        long long maxi=0;

        

        for(int i=l;i<=r;i++){
          sum+=nums[i];
          mpp[nums[i]]++;
        }

        if(mpp.size()==k)maxi=max(maxi,sum);

        while(r<n-1){
          
            r++;
            sum+=nums[r];
            mpp[nums[r]]++;
            sum-=nums[l];
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)mpp.erase(nums[l]);
            l++;
            
           

           if(mpp.size()==k)maxi=max(maxi,sum);
           
        }
        return maxi;
    }
};