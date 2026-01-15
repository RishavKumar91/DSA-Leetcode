class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pi = -1;
        int n = nums.size();
        if(n<2) return;
        int k = n-2;
        while(k>=0){
            if(nums[k]<nums[k+1]){ pi = k; break;}
            k--;
        }
        if(pi!=-1){
            k = n-1;
            while(nums[k]<=nums[pi]) k--;
            swap(nums[pi],nums[k]);
        }
        reverse(nums.begin()+pi+1,nums.end());


    }
};