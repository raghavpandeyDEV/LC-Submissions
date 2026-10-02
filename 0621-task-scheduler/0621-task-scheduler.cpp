class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26,0);
        for(int i=0;i<tasks.size();i++){
            hash[tasks[i]-'A']++;
        }
        priority_queue<int>pq;

        for(int i=0;i<26;i++){
            if(hash[i]!=0)pq.push(hash[i]);
        }
        int cnt=0;
        while(!pq.empty()){
            vector<int>temp;
        for(int i=1;i<=n+1;i++){
           if(!pq.empty()){
            int freq=pq.top();
            pq.pop();
            freq--;
            temp.push_back(freq);
           }
        }
           for(int i=0;i<temp.size();i++){
            if(temp[i]!=0)pq.push(temp[i]);
           }
           if(pq.size()==0){
            cnt+=temp.size();
           }
           else cnt+=(n+1);
        }
        
        return cnt;
    }
};