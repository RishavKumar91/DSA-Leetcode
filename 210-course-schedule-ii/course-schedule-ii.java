class Solution {
    ArrayList<ArrayList<Integer>> aj ;
    ArrayList<Integer> ans ;
    int visit[]; 
    public int[] findOrder(int n , int[][] prerequisites) {
        aj = new ArrayList<>(n); ans =  new ArrayList<>();
        visit = new int[n];
        for(int i = 0 ; i < n ; i++){
            aj.add(new ArrayList<>() ) ;
        }
        for(int tmp[] : prerequisites ){
            aj.get(tmp[1]).add(tmp[0]) ; 
        }
        for(int i = 0 ; i < n ; i++){
            if(visit[i] == 0){
                if(fs(i) == true ) return new int[0] ; 
            }
        }
        for(int i = 0 ; i < n ; i++){
            visit[n-i-1] = ans.get(i);
        }
    return visit ; 
    }
    boolean fs(int i){
        for(int ngbr : aj.get(i)){
            if(visit[ngbr] == 2) return true ;
            if(visit[ngbr] == 1) continue;
            visit[ngbr] = 2;
            if(fs(ngbr) == true) return true;
        }
    visit[i] = 1 ;
    ans.add(i) ;
    return false ;
    }
}