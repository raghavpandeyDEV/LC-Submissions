class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxi=INT_MIN;

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int el=st.top();
                st.pop();
                int nse=i;
                int pse = (st.empty()) ? -1: st.top();
                maxi=max(maxi,heights[el]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            //elements rem in stack do not have any nse
            int nse=heights.size();
            int el=st.top();
            st.pop();
            int pse = (st.empty()) ? -1: st.top();
            maxi=max(maxi,heights[el]*(nse-pse-1));
        }
    return maxi;
    }
};