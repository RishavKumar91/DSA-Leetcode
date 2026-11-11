class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long c1 = cost1 , c2 = cost2 , cb = costBoth , n1 = need1 , n2 = need2 ; 
        if(cost1 + cost2 <= costBoth) return c1*n1 + c2*n2 ; 
        else{
            long  minrq = Math.min(n1,n2);
            long maxrq = Math.max(n1,n2);
            return Math.min(cb*minrq + (n1-minrq)*(c1) + (n2-minrq)*(c2) , maxrq*costBoth );
        }
    }
}