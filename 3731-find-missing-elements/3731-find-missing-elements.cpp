class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        unordered_map<int,int>mpp;
        vector<int>ans;

        int n=nums.size();

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        for(int i=mini+1;i<maxi;i++){
        if(mpp.find(i)==mpp.end())ans.push_back(i);
        }

        return ans;
    }
};