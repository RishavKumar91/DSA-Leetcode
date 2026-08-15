class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n  = nums.size();
        int a = 0;
        bool allzero = 1;
        for(int i = 0 ; i < n ; i++){
            a = (a ^ nums[i]);
            if(nums[i] != 0) allzero = 0 ;
        }
        if(allzero == 1) return 0;
    return a == 0 ? n-1 : n ;
    }
};