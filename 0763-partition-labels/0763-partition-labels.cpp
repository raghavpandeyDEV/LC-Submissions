class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]=i;
        }

        int i=0;
        while(i<s.size()){
            int start=i;
            int end=mpp[s[i]];
            while(i<=end){
                end=max(end,mpp[s[i]]);
                i++;
            }
            ans.push_back(end-start+1);
            
        }
        return ans;
    }
};