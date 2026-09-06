class Solution {
public:
    int trap(vector<int>& height) {
        // water ? -> min(rmax , lmax)
        // 2 pointers -> max water -> smaller of two -> move pointer with smaller ht

        // lmax ,rmax -> if(lmax<rmax) -> lmax-arr[l] , l++;
        // rmax-arr[r] , r--;
        

        int l=0;
        int n=height.size();
        int r = n-1;

        int lmax=0;
        int rmax=0;

        int sum=0;

        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax, height[r]);

            if(lmax<rmax){
              sum+=(lmax-height[l]);
              l++;
            }
            else{
                sum+=(rmax-height[r]);
                r--;
            }
        }
        return sum;
    }
};