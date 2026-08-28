class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.size();
        vector<int>vis(n,0);

        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push(i);
            else{
              if(!st.empty()){
                int stop=st.top();
                vis[stop]=1;
                vis[i]=1;
                st.pop();
            }
        }
        }
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
          if(vis[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
          }
          else{
            cnt=0;
          }
        }

        return maxi;
    }
};