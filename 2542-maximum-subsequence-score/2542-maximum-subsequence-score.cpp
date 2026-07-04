class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        // use PQ for nums1 
        // sort desc order nums2

        vector<pair<int,int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums1[i],nums2[i]});
        }

        sort(v.begin(), v.end(), [](auto &p1, auto &p2) {
    return p1.second > p2.second;
});
        
           priority_queue<int,vector<int>,greater<int>> pq;

           long long sum=0;
           int min_el=v[k-1].second;

           for(int i=0;i<k;i++){
            sum+=v[i].first;
            pq.push(v[i].first);
           }

           long long score=sum*min_el;

           for(int i=k;i<nums1.size();i++){
            min_el=v[i].second;
            sum+=(v[i].first);
            sum-=(pq.top());
            pq.pop();

            pq.push(v[i].first);
            
            score=max(score,sum*min_el);
           }



return score;
        
    }
};