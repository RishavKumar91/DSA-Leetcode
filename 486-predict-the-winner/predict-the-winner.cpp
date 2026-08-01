class Solution {
public:
int n ;
    int hlpr(int i , int j , vector<int>& nums ){
        if(i > j) return 0 ;
        if(i==j) return nums[i];
        int last_take = nums[j] + min(hlpr(i,j-2,nums),hlpr(i+1,j-1,nums));
        int firsttake = nums[i] + min(hlpr(i+1,j-1,nums),hlpr(i+2,j,nums));
        return max(last_take,firsttake);

    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        int total = accumulate(nums.begin() , nums.end(),0);
        int max1 = hlpr(0,n-1,nums);
        return max1 >= total-max1 ; 
    }
};