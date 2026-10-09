class Solution {
    public int[] gardenNoAdj(int n, int[][] paths) {
        int[] ans = new int[n+1];
        Arrays.fill(ans,0);
        HashMap<Integer,ArrayList<Integer> > aj = new HashMap<>() ;
        for(int i = 0 ; i <= n ; i++) aj.put(i,new ArrayList<>());
        for(int i = 0 ; i < paths.length ; i++){
            aj.get(paths[i][0]).add(paths[i][1]) ; 
            aj.get(paths[i][1]).add(paths[i][0]) ; 
        }
        for(int i = 1 ; i <= n ; i++){
            if(ans[i] == 0){
                ArrayDeque<Integer> q = new ArrayDeque<>();
                q.add(i);
                ans[i] = 1;
                while(!q.isEmpty()){
                    int now = q.peekFirst() ;
                    q.pollFirst();
                    for(int ngbr : aj.get(now)){
                        if(ans[ngbr] != 0) continue ; 
                        boolean[] used = new boolean[5];
                        for (int x : aj.get(ngbr)) {
                                used[ans[x]] = true;
                            }
                            for (int c = 1; c <= 4; c++) {
                                if (!used[c]) {
                                    ans[ngbr] = c;
                                    break;
                                }
                            }
                    }
                }
            }
        }
    return Arrays.copyOfRange(ans, 1, n + 1);
    }
}