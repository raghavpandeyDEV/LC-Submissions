class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mpp;

        int l=0;
        int r=0;

        int n=s.size();
        int cnt=1;

        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                cnt++;
                l=r;
                mpp.clear();
            }
            mpp[s[r]]++;
            r++;

        }

        return cnt;
        
    }
};