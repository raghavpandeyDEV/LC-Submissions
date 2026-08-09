class Solution {
public:
    vector<int>nse(vector<int>&arr){
       
        int n=arr.size();
         vector<int>ans(n,n);
        stack<int>st; // indexes
        for(int i=n-1;i>=0;i--){
     while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
     if(!st.empty())ans[i]=st.top();
     st.push(i);
        }

        return ans;
    }

    vector<int>pse(vector<int>&arr){
       
        int n=arr.size();
         vector<int>ans(n,-1);
        stack<int>st; // indexes
        for(int i=0;i<n;i++){
     while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
     if(!st.empty())ans[i]=st.top();
     st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        vector<int>nSe=nse(heights);
        vector<int>pSe=pse(heights);

        for(int i=0;i<heights.size();i++){
            int area=heights[i]*(nSe[i]-pSe[i]-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};