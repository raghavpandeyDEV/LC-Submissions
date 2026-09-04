class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // making all Even is impossible { unless all Even case }

        //trying for all odd 
        int smallestOdd=1e9;
        int smallestEven=1e9;

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0)smallestEven=min(smallestEven,nums1[i]);
            else{
                smallestOdd=min(smallestOdd,nums1[i]);
            }
        }
      
      if(smallestOdd==1e9)return true;
      else if(smallestEven==1e9)return true;

      if(smallestOdd<smallestEven)return true;
      return false;
      

    }
};