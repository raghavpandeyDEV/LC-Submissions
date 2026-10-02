class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mpp;

        for(int i=0;i<s1.size();i++){
            mpp[s1[i]]++;
        }

        for(int i=0;i<s2.size();i++){
            if(mpp.find(s2[i])!=mpp.end()){
                unordered_map<char,int>temp=mpp;
                temp[s2[i]]--;
                if(temp[s2[i]]==0)temp.erase(s2[i]);
                int j=i+1;
                while(temp.size()!=0){
                    if(temp.find(s2[j])!=temp.end()){
                        temp[s2[j]]--;
                        if(temp[s2[j]]==0)temp.erase(s2[j]);
                        j++;
                    }
                    else{
                        break;
                    }
                }
                if(temp.size()==0)return true;
            }
        }
   return false;
    }
};