class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int prev=INT_MIN;
        int maxi=0;
        int cnt=0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(nums[i]==prev)continue;
            if(nums[i]==prev+1){
                cnt++;
                prev=nums[i];
            }
            else{
                cnt=1;
                prev=nums[i];
            }
       maxi=max(maxi , cnt);
        }
       
        return maxi;
    
    }
};