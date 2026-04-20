class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        for(int i =0;i<n;i++){
            deque<int> st ; int j = nums2.size()-1;
            while(nums2[j]!=nums1[i])  { st.push_back(nums2[j]); j--;}
            while(!st.empty() && st.back()<nums1[i]) st.pop_back();
            nums1[i] = st.size() ? st.back() :-1 ; 
        }
        return nums1 ;
    }
};