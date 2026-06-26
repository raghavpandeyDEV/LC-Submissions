class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q; // {word , steps}
        q.push({beginWord,1});
        unordered_set<string>st;
        for(auto it : wordList){
            st.insert(it);
        }
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            
            if(word==endWord)return steps;
            q.pop();

            for(int i=0;i<word.size();i++){
                char org=word[i];
                for(char ch = 'a'; ch<='z';ch++){
                  word[i]=ch;
                  if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                  }
                  
                }  
                word[i]=org;
            }

        }
        return 0;
    }
};