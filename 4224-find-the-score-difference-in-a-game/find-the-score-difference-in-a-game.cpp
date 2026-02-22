class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ans = 0;
        bool activ = 1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2==1 && (i+1)%6==0  ) ; //swap(activ1,activ2);
            else if(nums[i]%2==1 || (i+1)%6==0  ) activ = !activ;
            if(activ==1 ) ans+=nums[i];
            else ans-=nums[i];
        }
    return ans;
    }
};