class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> v ;
        int i=0,n= nums.size(),j=0;
        for(int i =0;i<n;i++){
            if(nums[i]!=val) nums[j++] = nums[i];
        }
        return j;
    }
};