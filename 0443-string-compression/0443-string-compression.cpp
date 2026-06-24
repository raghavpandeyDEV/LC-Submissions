class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int idx=0;
      

        while(i<n){
          int cnt=0;
          char curr_char=chars[i];

           while(i<n && chars[i]==curr_char){
            cnt++;
            i++;
           }
           chars[idx]=curr_char;
           idx++;
           if(cnt==1)continue;
           string val=to_string(cnt);
           for(auto it : val){
            chars[idx]=it;
            idx++;
           }
           
        }
        return idx;
    }
    
};