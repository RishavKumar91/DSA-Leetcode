class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1 + cost2 <= costBoth) return 1L *  cost1*need1 + 1L*cost2*need2 ; 
        else{
            int minrq = Math.min(need1,need2);
            int maxrq = Math.max(need1,need2);
            return Math.min(1L*costBoth*minrq + 1L*(need1-minrq)*(cost1) + 1L*(need2-minrq)*(cost2) , 1L*maxrq*costBoth );
        }
    }
}