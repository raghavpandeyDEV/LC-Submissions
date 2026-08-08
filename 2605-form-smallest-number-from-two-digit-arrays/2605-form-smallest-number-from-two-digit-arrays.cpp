class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        string ans="";
        
        

        if(nums1[0]>=nums2[0]){
        ans.push_back(nums2[0]+'0');
        ans.push_back(nums1[0]+'0');
        }
        else{
        ans.push_back(nums1[0]+'0');
        ans.push_back(nums2[0]+'0');
        }

        for(int i=0;i<nums1.size();i++){
            bool found=false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans="";
                    ans.push_back(nums1[i]+'0');
                    found=true;
                    break;
                }
            }
            if(found==true)break;
        }

     int res=stoi(ans);
     return res;

    }
};