class Solution {
    record Pair(int last , int srvr){}
    
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        PriorityQueue<Pair> busy = new PriorityQueue<>((a,b)->{
            return Integer.compare(a.last,b.last);
        });
        TreeSet<Integer> free = new TreeSet<>();
        int count[] = new int[k] ;
        int n = arrival.length ;
        for(int i = 0 ; i < k ; i++) free.add(i);
        for(int i = 0 ; i < n ; i++){
            while( !busy.isEmpty() && busy.peek().last <= arrival[i] ){
                free.add(busy.peek().srvr);
                busy.poll();
            }
            if(free.isEmpty()){
                continue ; 
                // free.add(busy.peek().srvr);
                // busy.poll();
            }
            int rq = i % k ;
            Integer curr = free.ceiling(rq); if(curr == null) curr = free.first();
            free.remove(curr);
            count[curr]++;
            busy.add(new Pair( load[i] + arrival[i] , curr));
        }
        int maxval = 0 ;
        for(int val : count){
            maxval = Math.max(val,maxval); 
        }
        List<Integer> ans = new ArrayList<>();
        for(int i = 0 ; i < k ; i++) if(count[i] == maxval) ans.add(i);
    return ans ;
    }
}