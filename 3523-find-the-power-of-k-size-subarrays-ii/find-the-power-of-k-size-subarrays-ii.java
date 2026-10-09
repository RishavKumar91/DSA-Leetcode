class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n-k+1];
        Arrays.fill(ans,-1);
        ArrayDeque<Integer> q = new ArrayDeque<>();
        int i = 0 ;
        while(i<k){
            
            if(q.isEmpty() ) q.add(nums[i]) ;
            else if(q.peekLast() +1 == nums[i]) q.add(nums[i]);
            else {
                q.clear();
                q.add(nums[i]) ;
            }
            if(q.size() > k) q.poll();
        i++;
        }
        ans[0] = (q.size() == k ? q.peekLast() : -1); 
        while(i<n){
            if(q.isEmpty() ) q.add(nums[i]) ;
            else if(q.peekLast() +1 == nums[i]) q.add(nums[i]);
            else {
                q.clear();
                q.add(nums[i]) ;
            }
            if(q.size() > k) q.poll();
            ans[i-k+1] = ((!q.isEmpty() && q.size() >= k) ? q.peekLast() : -1) ;
        i++;
        }
    return ans ; 
    }
}