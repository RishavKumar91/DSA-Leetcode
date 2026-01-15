class Solution {
public:
    void sortColors(vector<int>& nums) {
        int f = 0 ,mi = 0,l = nums.size()-1;
        while(mi<=l){
            if(nums[mi]==2) {swap(nums[mi],nums[l]) ;l--; }
            else if(nums[mi]==0)  {swap(nums[mi],nums[f]);mi++;f++;}
            else { mi++;}
        }
    }
};