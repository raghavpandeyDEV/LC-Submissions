class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int r=0;

        int n  = nums.size();

        int maxi=0;
        int zeroes=0;

        while(r<n){
            if(nums[r]==0)zeroes++;
            while(zeroes>1){
                if(nums[l]==0)zeroes--;
                l++;
            }
            if(zeroes<=1)maxi=max(maxi,r-l);
            r++;
        }
        return maxi;
    }
};