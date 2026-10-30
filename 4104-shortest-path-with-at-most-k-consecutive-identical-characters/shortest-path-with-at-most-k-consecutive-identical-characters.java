class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        ArrayList<ArrayList<int[]>> aj = new ArrayList<>();
        for(int i = 0 ; i < n ; i++){
            aj.add( new ArrayList<>() );
        }
        int visit[][] = new int[n+1][k+1]; 
        // System.out.print(visit[0][0]);
        for(int i = 0 ; i < n+1 ; i++){
            for(int j = 0 ; j < k+1 ; j++){
                visit[i][j] = Integer.MAX_VALUE;
            }
        }
        // System.out.print(visit[0][0]);
        for(int tmp[] : edges ){
            aj.get(tmp[0]).add(new int[]{tmp[1],tmp[2]});
            // aj.get(tmp[1]).add(new int[]{tmp[0],tmp[2]});
        }
        PriorityQueue<List<Integer> > pq = new PriorityQueue<>((a, b) -> Integer.compare(a.get(0), b.get(0))) ;    
        // {wt , dst , count}
        pq.offer(List.of(0,0,1));
        visit[0][1] = 0 ;
        while(!pq.isEmpty()){
            List<Integer> curr = pq.peek();
            pq.poll();
            int node  = curr.get(1); 
            int val   = curr.get(0); 
            int count = curr.get(2);
            if(count > k) continue ;
            if(node == n-1) return val ; 
            if( visit[node][count] != val ) continue ;
            for(int tmp[] : aj.get(node)){
                int newnode = tmp[0];
                int newval = tmp[1] + val;
                int ncount = labels.charAt(node) == labels.charAt(newnode) ? count + 1 :  1 ;
                if(ncount > k) continue ;
                if( visit[newnode][ncount] <= newval ) continue ;
                visit[newnode][ncount] = newval ;
                pq.offer(List.of(newval,newnode , ncount));
            }
        }
    return -1 ;
    }
}