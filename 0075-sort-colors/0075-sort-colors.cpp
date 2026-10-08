class Solution {
public:
    void sortColors(vector<int>& nums) {
        
         /*0 to low-1 -> 0
         low to mid-1 -> 1
         high+1 to n-1 -> 2*/

         int low=0;
         int mid=0;
         int n=nums.size();
         int high=n-1;

         while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
             swap(nums[mid],nums[high]);
             high--;
            }
         }
    }
};