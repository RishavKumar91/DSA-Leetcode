class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int playr1pnt = 0;
        int playr2pnt = 0;
        bool activ1 = 1;
        bool activ2 = 0;
        for(int i =0;i<n;i++){
            if(nums[i]%2==1 && (i+1)%6==0  ) ; //swap(activ1,activ2);
            else if(nums[i]%2==1 || (i+1)%6==0  ) swap(activ1,activ2);
            if(activ1==1 ) playr1pnt+=nums[i];
            else playr2pnt+=nums[i];
        }
    return playr1pnt-playr2pnt;
    }
};