
 bool cmp(vector<int>&a , vector<int>&b){
        return (a[1]<b[1]);
    }
    
class Solution {
public:

   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort in inc order of end time 
        sort(intervals.begin(), intervals.end(),cmp);

        int end=intervals[0][1];
        int cnt=0;

        for(int i=1;i<intervals.size();i++){
             if(intervals[i][0]<end)cnt++;
             else{
                end=intervals[i][1];
             }
        }
        return cnt;
    }
};