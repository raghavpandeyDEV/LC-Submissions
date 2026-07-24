class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int maxIndex=0;

        int cnt=0;
        while(r<n-1){
            for(int i=l;i<=r;i++){
                maxIndex=max(maxIndex,i+nums[i]);
            }
            cnt++;
            l=r+1;
            r=maxIndex;
        
        }
        return cnt;
    }
};