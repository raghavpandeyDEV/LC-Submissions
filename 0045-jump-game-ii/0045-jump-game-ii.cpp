class Solution {
public:
    int jump(vector<int>& nums) {
        
        int l=0;
        int r=0;
        int n = nums.size();

        if(n==1 )return 0;

        long long cnt=0;

        while(r<n){
            int maxi=0;
            for(int i=l;i<=r;i++){
                maxi=max(maxi,i+nums[i]);
            }
             cnt++;
            if(maxi>=n-1)return cnt;
            l=r+1;
            r=maxi;
           

        }
        return -1;
    }
};