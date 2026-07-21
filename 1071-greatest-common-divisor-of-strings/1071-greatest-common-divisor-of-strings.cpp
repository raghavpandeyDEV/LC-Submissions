class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)return "";
        int n1=str1.size();
        int n2=str2.size();
        int hcf = std::gcd(n1, n2); 
        int i=0;
        int j=0;

        string ans="";
        int cnt=0;

        while(i<n1 && cnt!=hcf){
         if(str1[i]==str2[j])
         {ans+=str1[i];
         cnt++;
         i++;
         j++;
         }
         else break;
        }
        return ans;
    }
};