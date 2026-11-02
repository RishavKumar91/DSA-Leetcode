class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length ; 
        Arrays.sort(nums);
        if(n==1) return 0;
        if(n==2) return Math.abs(nums[0]-nums[1]);
        long mid1 = nums[n/2] , ans1 = 0 ; //  mid2 = nums[n/2 + 1] , ans2 = 0   ;
        for(int num : nums){
            ans1 += Math.abs(mid1 - num);
            // ans2 += Math.abs(mid2 - num);
        }
    // return (int)Math.min(ans1,ans2) ;
    return (int)ans1;
    }
}