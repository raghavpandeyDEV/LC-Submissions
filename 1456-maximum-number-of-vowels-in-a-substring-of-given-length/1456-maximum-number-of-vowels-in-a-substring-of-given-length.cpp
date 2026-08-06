class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int maxi=0;
        int cnt=0;

        int l=0;
        int r=k-1;

        // initial window
        for(int i=l;i<=r;i++){
            if(isVowel(s[i]))cnt++;
        }
        maxi=cnt;

        while(r<n-1){
            r++;
            if(isVowel(s[r]))cnt++;
            
            if(isVowel(s[l]))cnt--;
            l++;

            maxi=max(maxi,cnt);
        }

        return maxi;
    }
};