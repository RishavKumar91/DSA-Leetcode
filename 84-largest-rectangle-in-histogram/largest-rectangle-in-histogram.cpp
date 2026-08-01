class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prvmin(n) , nxtmin(n) ; prvmin[0] = -1;  nxtmin[n-1] = n;
        stack<int> st;
        st.push(0);
        for(int i = 1 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i] ) st.pop();
            prvmin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    while(st.size()) st.pop();
    st.push(n-1);
        for(int i = n-2  ; i >= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i] ) st.pop();
            nxtmin[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, heights[i] * (nxtmin[i] - prvmin[i] -1 ));
        }
    return ans;
    }
};