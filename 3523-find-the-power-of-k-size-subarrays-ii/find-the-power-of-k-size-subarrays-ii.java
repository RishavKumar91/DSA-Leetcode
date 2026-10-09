class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int i = 0 , n = nums.length , ln = 0;
        int[] ans = new int[n-k+1]; 
        Arrays.fill(ans,-1);
        while(i<n){
            if(i>0 && nums[i] == nums[i-1] + 1) ln++;
            else ln = 1;
            if(  ln >= k ) ans[i-k+1] = nums[i];
        i++;
        }
    return ans;
    }
}