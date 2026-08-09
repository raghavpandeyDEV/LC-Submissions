class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        int m=nums1.size();
        int n=nums2.size();

        int i=0;
        int j=0;

        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m){
             temp.push_back(nums1[i]);
                i++;
        }

        while(j<n){
            temp.push_back(nums2[j]);
                j++;
        }
 
      double ans=0;

      if((m+n)%2==1){
       int index=(m+n)/2;
       ans=temp[index];

      }
      else{
        int index=(m+n)/2;
        ans=(double)(temp[index]+temp[index-1])/2;
      }
 return ans;
    }
};