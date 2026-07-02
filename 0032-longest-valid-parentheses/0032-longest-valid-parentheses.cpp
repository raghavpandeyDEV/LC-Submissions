class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        int open=0;
        int close=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(')open++;
            if(s[i]==')')close++;
            if(close==open)maxi=max(maxi,close+open);

           else if(close>open){
                open=0;
                close=0;
            }
        }

        open=0;
        close=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')open++;
            if(s[i]==')')close++;
            if(close==open)maxi=max(maxi,close+open);

           else if(open>close){
                open=0;
                close=0;
            }
        } 
        
        return maxi;
    }
};