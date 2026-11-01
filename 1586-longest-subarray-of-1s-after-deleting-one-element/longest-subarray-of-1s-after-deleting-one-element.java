class Solution {
    public int longestSubarray(int[] nums) {
        int count1 = 0 , n = nums.length , count0 = 0 , i = 0 , j = 0 , ans = 0 ;
        while(j < n ){
            if(nums[j] == 1) count1++;
            else count0++ ; 
            while(count0 > 1 ){
                if(nums[i] == 1) count1--;
                else count0-- ; 
            i++; 
            }
            ans = Math.max(ans,count0 == 0 ? count1-1 : count1);
        j++;
        }
    return ans ;
    }
}