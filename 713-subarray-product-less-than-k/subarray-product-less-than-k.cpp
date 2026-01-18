class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i =0,j=0,n=nums.size()-1,pro=1,count=0;
        while(j<=n){
            pro *=nums[j];
            while(pro>=k){  pro/=nums[i];i++;}
            count+=j-i+1;
        j++;
        }
        return count;
    }
};