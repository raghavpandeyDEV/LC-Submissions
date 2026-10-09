class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>>pq;
        long long cnt=0;

        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            while(!pq.empty() && start>pq.top())pq.pop();
            cnt+=pq.size();

            pq.push(end);
        }
        return cnt;
    }
};