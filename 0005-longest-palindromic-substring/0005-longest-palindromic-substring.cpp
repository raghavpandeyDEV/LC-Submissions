class Solution {
public:
    string expandFromCenter(int i ,int j , string&s){
        while(i>=0 && j<s.size()){
            if(s[i]!=s[j])break;
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {

        string ans="";
        
        for(int i=0;i<s.size();i++){
            string even=expandFromCenter(i,i+1,s);
            string odd=expandFromCenter(i,i,s);

            if(even.size()>ans.size()){
                ans=even;
            }
            if(odd.size()>ans.size()){
                ans=odd;
            }
        }
        return ans;
    }
};