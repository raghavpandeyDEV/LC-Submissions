class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int n=s.size();

        for(int i=n-1;i>=0;i--){
            if(s[i]==' '&& cnt==0){
                continue;
            }
           else if(s[i]==' ' && cnt!=0){
                break;
            }
            else{
            cnt++;
            }
        }
        return cnt;
    }
};