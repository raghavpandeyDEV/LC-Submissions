bool cmp(vector<int>&a , vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort on the basic on points[1]
        sort(points.begin(),points.end(),cmp);

        int end=points[0][1];
        int cnt=1;

        for(int i=1;i<points.size();i++){
            if(points[i][0]<=end)continue;
            else{
                end=points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};