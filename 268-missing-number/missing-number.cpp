class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
    //     int i=0;
    //     sort(nums.begin(),nums.end());
    //     for( i;i<n;i++){
    //         if(nums[i] != i) return i;
    //     }
    // return i;
    unordered_set<int> st;
    int i ;
    for(i=0;i<n;i++){
            st.insert(nums[i]);
        }
    for(i =0;i<n;i++){
        if(!st.count(i)) return i;
    }
    return i;
    }
};