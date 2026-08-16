class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;

        int maxi=0;

        int n= s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(')open++;
            else close++;

            if(close>open){
                open=0;
                close=0;
                continue;
            }
            if(open==close){
                maxi=max(maxi, 2*open);
            }
        }
        open=0;
        close=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]==')')open++;
            else close++;

            if(close>open){
                open=0;
                close=0;
                continue;
            }
            if(open==close){
                maxi=max(maxi, 2*open);
            }
        }
        return maxi;
    }
};