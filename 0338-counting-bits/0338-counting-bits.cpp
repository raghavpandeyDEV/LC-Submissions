class Solution {
public:
    int countOnes(int n){
        int ones=0;
        while(n!=0){
            int rem=n%2;
            if(rem==1)ones++;
            n/=2;
        }
        return ones;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
         ans.push_back(countOnes(i));
        }
        return ans;
    }
};