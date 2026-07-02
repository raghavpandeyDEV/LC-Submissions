class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        vector<int>vis(s.size(),0);

        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty()){
                    int matching_el=st.top();
                    st.pop();
                    vis[i]=1;
                    vis[matching_el]=1;
                }
            }
        }
        int maxi =0 , cnt =0;
        
        for(int i=0;i<vis.size();i++){
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