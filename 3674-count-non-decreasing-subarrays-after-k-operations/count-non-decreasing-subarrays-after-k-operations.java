class Solution {
    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length ;
        int cumsum[] = nums.clone();
        for(int i = 1 ; i < n ; i++){
            cumsum[i] += cumsum[i-1];
        }
        int NGR[] = new int[n];
        Arrays.fill(NGR,n);
        Stack<Integer> st = new Stack<>();
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.isEmpty() && nums[st.peek()] <= nums[i] ) st.pop();
            if(!st.isEmpty()) NGR[i] = st.peek();
            st.add(i);
        }
        int Optns[] = new int[n];
        for(int j = n-1 ; j >= 0 ; j--){
            int m = NGR[j];
            long curroptn = (m - j) * nums[j] - rangesum(j , m-1 , cumsum); 
            Optns[j] = (int) curroptn + ( m < n ?  Optns[m] : 0 ) ;
        }
        long ans = 0 ;
        int i = 0 , j = 0 ;
        ArrayDeque<Integer> deq = new ArrayDeque<>();
        while(j < n){
            while(!deq.isEmpty() && nums[deq.peekLast()] < nums[j] ){
                deq.pollLast();
            }
            deq.offerLast(j);
            while(i <= j ){
                int m = deq.peekFirst() ; 
                int optns = ( (nums[m] * (j-m+1)) - rangesum(m,j,cumsum) ) +  Optns[i] - Optns[m] ; 
                if(optns <= k) break;
            i++;
            if(deq.peekFirst() < i) deq.pollFirst() ; 
            }
            ans += (j-i+1);
        j++;
        }
    return ans ; 
    }
    int rangesum(int i , int j , int cumsum[]){
        if(i == 0) return cumsum[j];
        return cumsum[j] - cumsum[i-1];
    }
}
