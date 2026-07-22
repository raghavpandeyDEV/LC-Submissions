class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
       
        vector<int>ans;

        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]=i;
        }

         int i=0;
        while(i<n){
            int start=i;
            int maxRange=mpp[s[i]];
            while(i<=maxRange){
                maxRange=max(maxRange,mpp[s[i]]);
                i++;
            }
            ans.push_back(maxRange-start+1);

        }
        return ans;
    }
};