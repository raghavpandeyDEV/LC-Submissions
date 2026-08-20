class Solution {
public:
    
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;

        int l=0;
        unordered_map<int,int>mpp;
        int r=0;

        while(r<n){
         mpp[nums[r]]++;

         while(mpp[nums[r]]>k){
            mpp[nums[l]]--;

                if(mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }

                l++;
         }

         maxi=max(maxi,r-l+1);
         r++;

        }

        return maxi;
    }
};