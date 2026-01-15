class Solution {
public:
    int search(vector<int>& nums, int target) {
        int f = 0 , l = nums.size()-1;
        while(f<=l){
            int mi =(f+l)/2;
            if(nums[mi]==target) return mi;
            else if(nums[f]<=nums[mi]){
                if(nums[f]<=target && target<nums[mi]) l=mi-1;
                else f=mi+1;
            }
            else{
                if(nums[mi]<target && target<=nums[l]) f=mi+1;
                else l =mi-1;
            }
        }
        return -1;
    }
};