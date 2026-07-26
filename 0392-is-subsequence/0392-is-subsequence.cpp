class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int i=0;
        int j=0;
        while(j<n){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return (i==s.size());
    }
};