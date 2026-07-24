class Solution {
public:
    bool isValid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))return true;
        return false;
    }
    bool isPalindrome(string s) {
       string temp="";
       for(int i=0;i<s.size();i++){
        if(isValid(s[i]))temp.push_back(tolower(s[i]));
       }

       int i=0;
       int j=temp.size()-1;

       while(i<j){
        if(temp[i]!=temp[j])return false;
        i++;
        j--;
       } 
       return true;
    }
};