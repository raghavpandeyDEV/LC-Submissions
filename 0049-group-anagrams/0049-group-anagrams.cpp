class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;

        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mpp[strs[i]].push_back(word);
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};