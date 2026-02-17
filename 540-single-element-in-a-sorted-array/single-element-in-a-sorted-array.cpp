class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
    //     for(int i =0;i<n-1;i+=2){
    //         if(nums[i] != nums[i+1]) return nums[i];
    //     }
    // return nums[n-1];
        int start = 0,end = nums.size()-1;
        while(start<end){
            int mi = (start + end) /2;
            if(mi%2==1) mi = mi - 1;
            if(nums[mi]==nums[mi+1]) start = mi+2;
            else end = mi;
        }
    return nums[start];
    }
};