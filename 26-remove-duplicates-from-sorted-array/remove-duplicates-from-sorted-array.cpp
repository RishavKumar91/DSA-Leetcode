class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),count=0;
        int l=0,i=1;
        for(i;i<n;i++){
            if(nums[i-1]!=nums[i]) nums[l++] = nums[i-1];
        }
        nums[l++]=nums[i-1];
    return l;
    }
};