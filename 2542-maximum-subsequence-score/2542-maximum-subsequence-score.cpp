class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<pair<int,int>> v;

        for (int i = 0; i < nums1.size(); i++) {
          v.push_back({nums1[i], nums2[i]});
}

        sort(v.begin(), v.end(), [](auto &p1, auto &p2) {
    return p1.second > p2.second;
});
        
           priority_queue<int,vector<int>,greater<int>> pq;

           int min_el=v[k-1].second;
           long long ksum=0;
           for(int i=0;i<k;i++){
            ksum+=v[i].first;
            pq.push(v[i].first);
           }

        
        long long score=ksum*min_el;
        for(int i=k;i<nums1.size();i++){
            min_el=v[i].second;
            pq.push(v[i].first);
ksum += v[i].first;

ksum -= pq.top();
pq.pop();
        
        score=max(score,1LL * min_el * ksum);
            
        }
           return score;
    }
};