class Solution {
public:
    void nse(vector<int>arr , vector<int>&ans){
        stack<int>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
    }

    void pse(vector<int>arr , vector<int>&ans){
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);

        pse(heights, left);
nse(heights, right);

        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
          maxi=max(maxi,(right[i]-left[i]-1)*heights[i]);  
        }
        return maxi;
    }
};