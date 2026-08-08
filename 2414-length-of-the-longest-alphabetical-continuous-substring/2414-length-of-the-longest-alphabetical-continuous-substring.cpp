class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int maxi=1;

        for(int i=0;i<n;i++){
                int cnt=1;
                int prv=s[i]-'a'; // s[i]-'a'
                for(int j=i+1;j<n;j++){
                  if(s[j]-'a'==prv+1){
                    cnt++;
                    
                    maxi=max(maxi,cnt);
                    prv=s[j]-'a';
                  
                  }
                  else break;
                }
            
        }
        return maxi;
    }
};