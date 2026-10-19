class Solution {
    int n ;
    int nCr[][] ;
    int M = 1000000007 ; 
    public int numOfWays(int[] nums) {
        n = nums.length ; 
        nCr = new int[n+1][n+1];
        for (int i = 0; i <= n; i++) {
            nCr[i][0] = 1;
            nCr[i][i] = 1;
        }
        for(int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j < i ; j++){
                nCr[i][j] = (int)(((long)nCr[i-1][j-1] + nCr[i-1][j]) % M);
            }
        }
    return ( hlpr(nums) - 1 + M ) % M  ; 
    }
    int hlpr(int[] nums){
        int sz = nums.length ; 
        if(sz <= 2) return 1;
        ArrayList<Integer> lft = new ArrayList<>();
        ArrayList<Integer> rgt = new ArrayList<>();
        int root = nums[0];
        for(int i = 0 ; i < sz ; i++){
            if(nums[i] < root ) lft.add(nums[i]);
            else if(nums[i] > root ) rgt.add(nums[i]);
        }
        long ans = hlpr(lft.stream().mapToInt(Integer::intValue).toArray());
        ans = ans * hlpr(rgt.stream().mapToInt(Integer::intValue).toArray()) % M;
        ans = ans * nCr[sz - 1][lft.size()] % M;
    return (int)ans ;
    }
}