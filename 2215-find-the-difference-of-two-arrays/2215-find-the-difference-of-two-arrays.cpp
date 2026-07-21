class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        vector<int>ans0;
        vector<int>ans1;
        map<int,int>mp1;
        map<int,int>mp2;

        int s1=nums1.size();
        int s2=nums2.size();

        for(int i=0;i<s1;i++){
            mp1[nums1[i]]++;
        }

        for(int i=0;i<s2;i++){
            mp2[nums2[i]]++;
        }
        
        for(auto it : mp1){
            if(mp2.find(it.first)==mp2.end())ans0.push_back(it.first);
        }

        for(auto it : mp2){
            if(mp1.find(it.first)==mp1.end())ans1.push_back(it.first);
        }

        ans.push_back(ans0);
        ans.push_back(ans1);
       

        return ans;

    }
};