class Solution {
public:
     string decToBinary(int n) {
        string res="";
        while(n!=1){
           res+=(n%2)+'0';
           n=n/2;
        }
        res+=(n)+'0';
        reverse(res.begin(),res.end());
        return res;
    }

    int hammingWeight(int n) {
        string ans=decToBinary(n);
        int cnt=0;
        for(int i=0;i<ans.size();i++){
          if(ans[i]=='1')cnt++;
        }

    return cnt;

    }
};