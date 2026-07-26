class Solution {
public:
    string simplifyPath(string path) {
         stack<string> st;
        string curr;

        stringstream ss(path);

        while(getline(ss, curr, '/')){
            if(curr=="" || curr==".")continue;
            else if(curr==".."){
                if(!st.empty())st.pop();
            }
            else{
                st.push(curr);
            }
        }

        string ans="";
        if(st.empty())return "/";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        return ans;
    }
};