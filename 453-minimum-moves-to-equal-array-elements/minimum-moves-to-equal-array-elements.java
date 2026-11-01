class Solution {
    public int minMoves(int[] nums) {
        int minval = Integer.MAX_VALUE , n = nums.length; 
        for(int i = 0 ; i < n ; i++){
            minval = Math.min(minval,nums[i]);
        }
        int ans = 0; 
        for(int num : nums ){
            ans += num-minval ;
        }
    return ans ; 
    }
}