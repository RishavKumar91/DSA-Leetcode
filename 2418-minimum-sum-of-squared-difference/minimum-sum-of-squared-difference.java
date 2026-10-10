class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        k1 += k2 ;
        int[] difffrq = new int[100001] ;
        for(int i = 0 ; i < n ; i++){
            difffrq[Math.abs(nums1[i] - nums2[i])]++ ;
        }
        for(int i = 100000 ; i >= 1 && k1 > 0 ; i--){
            int k = Math.min(k1,difffrq[i]);
            difffrq[i] -= k ;
            difffrq[i-1] += k ;
            k1 -= k ; 
        }
        long ans = 0 ;
        for(int i = 1 ; i <= 100000 ; i++){
            ans += (long)i * i * difffrq[i];
        }
    return ans;
    }
}