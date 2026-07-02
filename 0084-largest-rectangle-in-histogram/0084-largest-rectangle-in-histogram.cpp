class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxi=INT_MIN;
        int n=heights.size();

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int el=st.top();
                st.pop();
                int nse=i;
                int pse=(st.empty())?-1:st.top();

                maxi=max(maxi,(nse-pse-1)*heights[el]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse=n;
            int el=st.top();
            st.pop();
             int pse=(st.empty())?-1:st.top();
             maxi=max(maxi,(nse-pse-1)*heights[el]);
        }
        return maxi;
    }
};