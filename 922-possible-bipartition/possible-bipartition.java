class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        ArrayList<List<Integer > > aj = new ArrayList<>();
        for (int i = 0; i < n+1; i++)  aj.add(new ArrayList<>());
        for(int[] tmp : dislikes){
            aj.get(tmp[0]).add(tmp[1]);
            aj.get(tmp[1]).add(tmp[0]);
        }
        int[] visit = new int[n+1];
        Arrays.fill(visit,0);
        for(int i = 1 ; i < n + 1 ; i++){
            if(visit[i] != 0) continue ;
            Queue<Integer> q = new ArrayDeque<>();
            q.offer(i);
            visit[i] = 1;
            while(!q.isEmpty()){
                int front = q.poll();
                int fill = visit[front] == 1 ? 2: 1 ; 
                for(int ngbr : aj.get(front)){
                    if(visit[ngbr] == fill ) continue;
                    if(visit[ngbr] != 0 ) return false;
                    visit[ngbr] = fill;
                    q.offer(ngbr);
                }
            }
        }
    return true;
    }
}