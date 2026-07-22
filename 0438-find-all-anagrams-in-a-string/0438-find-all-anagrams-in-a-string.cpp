class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int>ans;
       int n=p.size();
       unordered_map<char,int>mpp; // {char , freq}
       for(int i=0;i<p.size();i++){
          mpp[p[i]]++;
       }

    
     // map : remove ++ , insert --
     
      for(int i=0;i<n;i++){
        mpp[s[i]]--;
        if(mpp[s[i]]==0)mpp.erase(s[i]);
      }
      if(mpp.size()==0)ans.push_back(0);

      int l=0;
      int r=n-1;
      while(r<s.size()-1){
        r++;
        mpp[s[r]]--;
          if (mpp[s[r]] == 0)
       mpp.erase(s[r]);
        mpp[s[l]]++;
        if (mpp[s[l]] == 0)
       mpp.erase(s[l]);
        l++;
        
        
        if(mpp.size()==0)ans.push_back(l);
      }

   return ans;
    }
};