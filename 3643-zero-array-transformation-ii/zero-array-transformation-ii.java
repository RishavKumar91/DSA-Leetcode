class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length , m = queries.length ;
        int j = 0 ;
        int DAT[] = new int[n+1]; 
        int cumsum = 0 ; 
        for(int i = 0 ; i < n ; i++){
            cumsum += DAT[i];
            while(cumsum < nums[i]){
                if(j == m) return -1 ;
                int start = queries[j][0];
                int last  = queries[j][1];
                int val   = queries[j][2];
                DAT[start] += val ;
                DAT[last+1]  -= val ; 
                if(start <= i && i <= last){
                    cumsum += val ;
                }
            j++;
            }
        }
    return j ; 
    }
}