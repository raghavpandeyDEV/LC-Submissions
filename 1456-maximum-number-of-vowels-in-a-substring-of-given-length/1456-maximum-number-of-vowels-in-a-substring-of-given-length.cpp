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

        for(int i=0;i<k;i++){
            if(isVowel(s[i]))cnt++;
            maxi=max(maxi,cnt);
        }
    
        while(r < n-1){
        // r ko move krne k baad check kro ki naya wala vowel h kya
         r++;
         if(isVowel(s[r]))cnt++;
         // l ko move krne k phle check kro vowel h ya ni
         if(isVowel(s[l]))cnt--;
         l++;
        
         maxi=max(maxi,cnt);

        }

       return maxi;
    }
};