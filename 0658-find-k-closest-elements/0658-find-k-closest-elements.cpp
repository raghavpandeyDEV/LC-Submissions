class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<pair<int,int>>dist(n); // {dist, element}
        vector<int>ans(k);

        for(int i=0;i<n;i++){
            int distance=abs(arr[i]-x);
            dist[i]={distance , arr[i]};
        }
     
     sort(dist.begin(),dist.end());
     for(int i=0;i<k;i++){
        ans[i]=dist[i].second;
     }

    sort(ans.begin(),ans.end());
    return ans;
    }
};