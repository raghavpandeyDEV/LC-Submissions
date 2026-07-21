class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int ,int > mpp;
        int cnt=0;

        for(int i=0 ;i<nums.size();i++){
           int rem=k-nums[i];
           if(mpp.find(rem)!=mpp.end()){
            cnt++;
            mpp[rem]--;
            if(mpp[rem]==0)mpp.erase(rem);
           }
           else{
            mpp[nums[i]]++;
           }
        }
        return cnt;
    }
};