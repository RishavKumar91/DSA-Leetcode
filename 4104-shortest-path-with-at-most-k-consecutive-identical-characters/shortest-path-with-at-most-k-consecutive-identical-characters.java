class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {

        ArrayList<ArrayList<int[]>> aj = new ArrayList<>();

        for(int i = 0; i < n; i++){
            aj.add(new ArrayList<>());
        }

        int[][] visit = new int[n][k+1];

        for(int i = 0; i < n; i++){
            Arrays.fill(visit[i], Integer.MAX_VALUE);
        }

        for(int[] tmp : edges){
            aj.get(tmp[0]).add(new int[]{tmp[1], tmp[2]});
        }

        // {weight, node, count}
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a[0], b[0])
        );

        pq.offer(new int[]{0, 0, 1});
        visit[0][1] = 0;

        while(!pq.isEmpty()){

            int[] curr = pq.poll();

            int val = curr[0];
            int node = curr[1];
            int count = curr[2];

            if(visit[node][count] != val) continue;

            if(node == n-1) return val;

            for(int[] tmp : aj.get(node)){

                int newnode = tmp[0];
                int newval = val + tmp[1];

                int ncount = labels.charAt(node) == labels.charAt(newnode)
                             ? count + 1 : 1;

                if(ncount > k) continue;

                if(visit[newnode][ncount] <= newval) continue;

                visit[newnode][ncount] = newval;

                pq.offer(new int[]{newval, newnode, ncount});
            }
        }

        return -1;
    }
}