class Solution {
    public int jump(int[] nums) {
        int n = nums.length , ans = 0 , last = 0 , i = 0 ;
        while( last < n-1 ){
            ans++;
            int olast = last ;
            while( i <= olast ){
                last = Math.max(last, nums[i]+i);
                i++;
            }
        }
    return ans ;
    }
}