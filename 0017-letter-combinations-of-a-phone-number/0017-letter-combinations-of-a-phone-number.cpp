class Solution {
public:
    void solve(int i , string digits , string&temp, unordered_map<char,string>&mpp,vector<string>&ans ){
      if(i==digits.size()){
        ans.push_back(temp);
        return;
      }
      char num=digits[i];
      for(auto it : mpp[num]){
        temp.push_back(it);
        solve(i+1,digits,temp,mpp,ans);
        temp.pop_back();
      }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";

        string temp="";
vector<string>ans;
        solve(0,digits,temp,mpp,ans);
        return ans;
     

    }
};