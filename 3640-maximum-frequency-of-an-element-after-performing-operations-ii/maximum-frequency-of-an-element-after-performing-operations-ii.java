class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int n = nums.length ;
        ArrayList<int[]> events = new ArrayList<>();
        HashMap<Integer,Integer> frqtable = new HashMap<>();
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            int minval = Math.max(0,curr-k) ;
            // int maxval = Math.min(max,curr+k);
            int maxval = curr+k ;
            events.add(new int[]{minval,1}) ;
            events.add(new int[]{maxval+1,-1}) ;
            events.add(new int[]{curr,0}) ;
            frqtable.put(curr,frqtable.getOrDefault(curr,0)+1);
        }
        int currsum = 0 , ans = 1 ;
        events.sort((a,b) -> Integer.compare(a[0],b[0]));
        for (int i = 0; i < events.size();) {
    int x = events.get(i)[0];

    while (i < events.size() && events.get(i)[0] == x) {
        currsum += events.get(i)[1];
        i++;
    }

    int frqncy = frqtable.getOrDefault(x, 0);
    ans = Math.max(ans, Math.min(currsum, frqncy + numOperations));
}
    return ans ;
    }
}