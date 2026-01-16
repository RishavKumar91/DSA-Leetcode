class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(),i=0,j=0,maxx=0,frqzr=0;
        while(j<n){
            if(nums[j]==0) frqzr++;
            if(frqzr>k) { while(nums[i]!=0)  i++; i++;frqzr--;}
            maxx = max(maxx,j-i+1);
            j++;
        }
    return maxx;
    }
};