class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        /* r-> l: find where inc nature end (mark it as idx)
         r->l : find just greater thn idx
         swap with idx
         reverse(idx+1,n-1)*/

         int n=nums.size();
         int idx=-1;

         for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                idx=i-1;
                break;
            }
         }
         if(idx==-1){
         reverse(nums.begin(),nums.end());
        return;
         }

         for(int i=n-1;i>=idx;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
         }

         sort(nums.begin()+idx+1,nums.end());
    }
};