class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),count=0;
        int l=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]!=nums[i]) nums[l++] = nums[i];
        }


        // int l=0,i=0;
        // for(i=0;i<n-1;i++){
        //     if(nums[i]!=nums[i+1]) nums[l++] = nums[i];
        // }
        // nums[l++] = nums[i];
    return l;
    }
};