class Solution {
public:
    void solve(int open , int close , int n, string temp, vector<string>&ans ){
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
           solve(open+1 , close, n, temp+'(',ans);
        }
        if(close<open){
           solve(open , close+1,n,temp+')',ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
         solve(0,0,n,temp,ans);
        return ans;
    }
};