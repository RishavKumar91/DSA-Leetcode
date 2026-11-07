class Solution {
    record Pair(long x , int y) {}
    public int mostBooked(int n, int[][] meetings) {
        int ans = 0 ; 
        Arrays.sort(meetings, (a,b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> free = new PriorityQueue<>();
        for(int i = 0 ; i < n ; i++) free.offer(i);
        PriorityQueue<Pair> busy = new PriorityQueue<>((Pair a , Pair b) ->{
            if(a.x == b.x) return Integer.compare(a.y,b.y);
            return Long.compare(a.x,b.x);
        });
        int count[] = new int[n];
        for(int meet[] : meetings){
            long start = meet[0];
            long time = meet[1] - meet[0];
            while(!busy.isEmpty() && busy.peek().x <= start ){
                free.offer(busy.poll().y);
            }
            if(free.isEmpty()){
                Pair p = busy.poll();
                free.offer(p.y);
                start = p.x ; 
            }
            int freeroom = free.poll();
            busy.add(new Pair( start + time ,freeroom));
            count[freeroom]++; 
        }
        
        for(int i = 1; i < n; i++) {
            if(count[i] > count[ans]) {
                ans = i;
            }
        }
    return ans ;
    }
}