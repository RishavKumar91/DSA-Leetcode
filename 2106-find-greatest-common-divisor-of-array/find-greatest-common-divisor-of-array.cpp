class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxx=INT_MIN,minn=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minn) minn= nums[i];
            if(nums[i]>maxx) maxx= nums[i];
        }
        for(int i =min(minn,maxx);i>=1;i--) {
            if(minn%i==0 && maxx%i==0) return i;
        }
        return 1;
    }
};