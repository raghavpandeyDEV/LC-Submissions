class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maxi(nums.size());
        vector<int>mini(nums.size());

        int maxEl=nums[0];
        maxi[0]=nums[0];
        
        int minEl=nums[nums.size()-1];
          mini[nums.size()-1]=nums[nums.size()-1];

        
        for(int i=1;i<nums.size();i++){
            maxi[i]=max(nums[i],maxi[i-1]);
        }

        for(int i=nums.size()-2;i>=0;i--){
            mini[i]=min(nums[i],mini[i+1]);
        }

        for(int i=0;i<nums.size();i++){
            if(maxi[i]-mini[i]<=k)return i;
        }
        return -1;
    }
};