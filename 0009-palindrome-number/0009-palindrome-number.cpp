class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int num=x;
        long long rev=0;
        while(x!=0){
            int digit=x%10;
            rev=rev*10+digit;
            x/=10;
        }
        if(rev==num)return true;
        return false;
    }
};