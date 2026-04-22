class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int m = nums1.size() , n = nums2.size();
        stack<int> st;
        for(int i = n-1;i>=0;i--) {
            while(!st.empty() && st.top()<nums2[i]) st.pop();
            if(!st.empty()) mp[nums2[i]] = st.top();
            else mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0 ;i<m;i++){
            ans.push_back(mp[nums1[i]]);
        }
    return ans;
    }
};