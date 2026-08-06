class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>hash(26,0);

        for(int i=0;i<ransomNote.size();i++){
            hash[ransomNote[i]-'a']++;
        }

        for(int i=0;i<magazine.size();i++ ){
           if(hash[magazine[i]-'a']!=0) hash[magazine[i]-'a']--;
        }

    for(int i=0;i<26;i++){
        if(hash[i]!=0)return false;
    }
    return true;
    }
};