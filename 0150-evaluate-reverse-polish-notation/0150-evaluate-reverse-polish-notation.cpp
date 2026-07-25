class Solution {
public:
   bool isDigit(int i){
    if(i>=-200 && i<=200)return true;
    return false;
   }
    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else{
                int second = st.top();
                st.pop();
                int first=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(first+second);
                }
                else if(tokens[i]=="-"){
                    st.push(first-second);
                }
                else if(tokens[i]=="*"){
                    st.push(first*second);
                }
                else if(tokens[i]=="/"){
                    st.push(first/second);
                }
            }

        }
        return st.top();
    }
};