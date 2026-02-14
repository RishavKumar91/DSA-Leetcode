class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int m = nums1.size();
        int n = nums2.size();
        unordered_set<int> s;
        unordered_set<int> ans;
        for(int i =0;i<m;i++){
            s.insert(nums1[i]);
        }
        for(int i =0;i<n;i++){
            if(s.count(nums2[i])) ans.insert(nums2[i]);
        }
        for(auto x : ans){
            v.push_back(x);
        }
    return v;
    }
};