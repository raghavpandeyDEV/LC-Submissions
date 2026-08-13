class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       priority_queue<pair<int,int>>pq;
        // { dis , element}
        vector<int>ans;

        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x), arr[i]});
        }
        while(pq.size()>k)pq.pop();
        while(!pq.empty()){
          ans.push_back(pq.top().second);
          pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};