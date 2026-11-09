class Solution {
    record Pair(int dist , int node){}
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<int[] >> aj = new ArrayList<>();
        for(int i = 0 ; i < n ; i++) aj.add(new ArrayList<>());
        for(int tmp[] : flights){
            aj.get(tmp[0]).add(new int[]{tmp[1],tmp[2]});
        }

        int dist[] = new int[n];
        Arrays.fill(dist,100000);
        dist[src] = 0 ;
        int stops = 0 ;
        ArrayDeque<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(0,src));
        while(!q.isEmpty()){
            if(stops == k+1) break ;
            stops++;
            int size = q.size();
            int dummy[] = dist.clone();
            for(int i = 0 ; i < size ; i++){
                Pair tmp = q.peek();
                q.poll();
                for(int ngbr[] : aj.get(tmp.node) ){
                    if(dummy[ngbr[0]] > ngbr[1] + dist[tmp.node]){
                        dummy[ngbr[0]] =  ngbr[1] + dist[tmp.node] ; 
                        q.add(new Pair(dist[ngbr[0]],ngbr[0]));
                    }
                }
            }
            dist = dummy ;
        }
    return dist[dst] == 100000 ? -1 : dist[dst];
    }
}