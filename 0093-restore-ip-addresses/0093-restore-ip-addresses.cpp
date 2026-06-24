class Solution {
public:

    bool isValid(string s){
        if(s[0]=='0')return false;

        int val=stoi(s);
         return val <= 255;
    }
    void solve(int idx , string s, string curr , vector<string>&ans , int parts){
        int n=s.size();
        if(idx==n && parts==4){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(parts>4)return;

        if(idx+1<=n){
        solve(idx+1,s,curr+s.substr(idx,1)+".",ans,parts+1);
        }

        if(idx+2<=n && isValid(s.substr(idx,2))){
        solve(idx+2,s,curr+s.substr(idx,2)+'.',ans,parts+1);
        }

        if(idx+3<=n && isValid(s.substr(idx,3))){
        solve(idx+3,s,curr+s.substr(idx,3)+'.',ans,parts+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if(s.size() < 4 || s.size() > 12)
        return {};
        string curr="";
        solve(0,s,curr,ans,0);
        return ans;
    }
};